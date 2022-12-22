#include "common.h"

static inline bool is_big_endian() {
    union {
        uint32_t i;
        char c[4];
    } e = { 0x01000000 };

    return e.c[0] == 1;
}


static void crypto_internal_swap_endian_in_place(uint8_t *p_buffer, size_t size) {
    uint8_t temp;
    uint8_t * p_first = p_buffer;
    uint8_t * p_last = p_buffer + size - 1;
    while (p_last >= p_first) {
        temp = *p_first;
        *p_first = *p_last;
        *p_last = temp;
        p_first++;
        p_last--;
    }
}

int ecdsa_verify(void *L) {
	int res = 0;
	char *message = "";
	char bytes_size;

	const struct uECC_Curve_t *curve = NULL;

	if (lua_gettop(L) != 4) {
		message = "invalid args";
		goto __exit;
	}

	char *type = luaL_checkstring(L, 1);
	if (strcmp(type, "secp160r1") == 0) {
		curve = uECC_secp160r1();
		bytes_size = 40;
	} else if (strcmp(type, "secp192r1") == 0) {
		curve = uECC_secp192r1();
		bytes_size = 48;
	} else if (strcmp(type, "secp224r1") == 0) {
		bytes_size = 56;
		curve = uECC_secp224r1();
	} else if (strcmp(type, "secp256r1") == 0) {
		bytes_size = 64;
		curve = uECC_secp256r1();
	} else if (strcmp(type, "secp256k1") == 0) {
		bytes_size = 64;
		curve = uECC_secp256k1();
	} else {
		message = "curve unsuported";
		goto __exit;
	}

	size_t len = 0;
	uint8_t *pk = (uint8_t *)lua_tolstring(L, 2, &len);
	if (len != bytes_size) {
		message = "invalid pk len";
		goto __exit;
	}

	uint8_t *hash = (uint8_t *)lua_tolstring(L, 3, &len);
	if (len != 32) {
		message = "invalid hash len";
		goto __exit;
	}

	uint8_t *sig = (uint8_t *)lua_tolstring(L, 4, &len);
	if (len != bytes_size) {
		message = "invalid pk len";
		goto __exit;
	}

	uint8_t hh[32];
    for (int i = 0; i < 32; ++i) {
        hh[i] = hash[31 - i];
    }

	if (!uECC_verify(pk, hh, 32, sig, curve)) {
		message = is_big_endian() ? "verify faild(be)" : "verify faild(le)";
		goto __exit;
	}

	res = 1;

__exit:
	lua_pushboolean(L, res);
	lua_pushstring(L, message);
	return 2;
}

luaL_Reg user_lib[] = {
	{"ecdsa_verify", ecdsa_verify},
	{NULL, NULL}};
	

int user_main(void *L) {
	luaI_openlib(L, "ecc", user_lib, 0);
	return 1;
}
