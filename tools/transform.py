import os
import sys
import re
import argparse
import shutil 


#将头文件转化为函数指针
def transform(args):
	pattern = "([\*\w]+[\s|\*]+?)\s?([\w]+)\s*?(\([\s\S]*?\));"
	c_include = "(\#include\s?[\w\S]+)"

	file = open(args.inter,mode = "r",encoding='utf-8')
	tr_h = open(args.out,"w")
	tr_c = open(args.out_c,"w")

	if not file:
		exit(0)

	c_head = file.read()
	#print(c_head)
	tmp1arr = re.findall(c_include,c_head,re.M|re.I)
	for temp in tmp1arr:
		tr_h.write(temp + "\n")
		tr_c.write(temp + "\n")

	tmp1arr = re.findall(pattern,c_head,re.M|re.I)
	#tr_h.write("#pragma once \n")
	#  void (*OPENAT_lua_print)(char * fmt, ...) = (void*) 0xffffffff;
	for temp in tmp1arr:
		new_function = temp[0] + "(*" + temp[1].strip() + ')' + temp[2] + " = (void*) 0xFFFFFFFF;"
		new_head = "extern " + temp[0] + "(*" + temp[1].strip() + ')' + temp[2] + ";"

		tr_h.write(new_head + "\r\n")
		tr_c.write(new_function + "\r\n")
	
	file.close()
	tr_h.close()
	tr_c.close()


def clear_files(argv):
	#print(argv.file)
	try:
		for temp in argv.file:
			#print(temp + '\n')
			os.remove(temp)
	except:
		pass

def transform_args(sub_parser):
	parse = sub_parser.add_parser('transform', help='transform c head to a function pointer')
	parse.set_defaults(func=transform)
	parse.add_argument('-i',dest='inter', required=True,
		help='input file ready to transform')
	parse.add_argument('-o',dest='out', required=True,
		help='transformed c head file to output')
	parse.add_argument('-oc',dest='out_c', required=True,
		help='transformed c file to output')

#删除文件
def clear_args(sub_parser):
	parse = sub_parser.add_parser('clear', help='delete file')
	parse.add_argument('-f',dest='file', required=True,nargs='+',
		help='clear files')
	parse.set_defaults(func=clear_files)

def move_files(argv):
	#print(argv.file)
	try:
		for temp in argv.file:
			_,filename = os.path.split(temp)
			#print(filename)
			#print(temp + '\n')
			#print(argv.dest+"\\"+filename)
			shutil.copyfile(temp,argv.dest+"\\"+filename)
	except:
		pass

#移动文件
def move_args(sub_parser):
	parse = sub_parser.add_parser('move', help='move file')
	parse.add_argument('-f',dest='file', required=True,nargs='+',
		help='move files')
	parse.add_argument('-d',dest='dest',required=True, help='move files to dir')
	parse.set_defaults(func=move_files)


def main(argv):
	parser = argparse.ArgumentParser(description='transform c head',
                                     formatter_class=argparse.RawTextHelpFormatter)
	sub_parser = parser.add_subparsers(help='sub-commnads')
	transform_args(sub_parser)
	clear_args(sub_parser)
	move_args(sub_parser)

	args = parser.parse_args(argv)
	if args.__contains__('func'):
		return args.func(args)
	else:
		parser.parse_args(["-h"])
		return 0

if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))

