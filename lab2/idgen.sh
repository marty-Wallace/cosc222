#!/bin/bash
touch stu_id/students.txt
U=0
N=0
D=0
if [[ "$#" -ne 0 ]]; then
	while true; do
		case "$1" in 
			-n)
			case "$2" in 
				"") N='10'; shift 2;; 
				*) N=$2; shift 2 ;;
			esac ;;
		-d)
			case "$2" in 
				"") D=1; shift 2;;
				*) D=$2; shift 2;;
			esac ;;
		-u) U=1; shift ;;
		*) shift; break ;;
		 esac
	done	
fi

stu_id/./idgen -n "$N" -d "$D" 
if [[ "$U" -gt 0 ]]; then
	mv stu_id/students.txt stu_id/students2.txt && cat stu_id/students2.txt | sort | uniq > stu_id/students.txt && rm stu_id/students2.txt
fi
