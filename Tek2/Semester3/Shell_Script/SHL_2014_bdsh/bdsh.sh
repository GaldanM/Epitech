#!/bin/sh
## bdsh.sh for bdsh in /home/moulin_c/rendu/SHL_2014_bdsh
## 
## Made by Galdan Moulinneuf
## Login   <moulin_c@epitech.net>
## 
## Started on  Mon Jan  5 14:09:36 2015 Galdan Moulinneuf
## Last update Tue Jan  6 21:55:34 2015 Galdan Moulinneuf
##

FUNC="null"
PARAM_1="null"
PARAM_2="null"
SEPAR="^"
FILE_NAME="sh.db"
F=0
P=0

put_func()
{
    if [ ! -e $FILE_NAME ]
    then
	`touch $FILE_NAME`
    fi
    FLAG=0
    if [ $(echo $PARAM_1 | cut -c 1) = "$" ]
    then
	PARAM_1=`echo $PARAM_1 | cut -c 2-`
	FLAG=1
	VAR=`grep "$PARAM_1" $FILE_NAME`
	for str in $VAR
	do
	    if [ $(echo $str | cut -d $SEPAR -f 1) = $PARAM_1 ]
	    then
		PARAM_1=`echo $str | cut -d $SEPAR -f 2`
		if [ -z $PARAM_1 ]
		then
		    echo "No such key : $PARAM_1" > /dev/stderr
		    exit 1
		fi
		FLAG=2
	    fi
	done
	if [ $FLAG = 1 ]
	then
	    echo "No such key : $PARAM_1" > /dev/stderr
	    exit 1
	fi
    fi
    FLAG=0
    if [ $PARAM_2 ] && [ $(echo $PARAM_2 | cut -c 1) = "$" ]
    then
	PARAM_2=`echo $PARAM_2 | cut -c 2-`
	FLAG=1

	VAR=`grep "$PARAM_2" $FILE_NAME`
	for str in $VAR
	do
            if [ $(echo $str | cut -d $SEPAR -f 1) = $PARAM_2 ]
	    then
		PARAM_2=`echo $str | cut -d $SEPAR -f 2`
		FLAG=2
	    fi
	done
	if [ $FLAG = 1 ]
	then
	    echo "No such key : $PARAM_2" > /dev/stderr
	    exit 1
	fi
    fi
    VAR=`grep "$PARAM_1" $FILE_NAME`
    FLAG_2=0
    for str in $VAR
    do
        if [ $(echo $str | cut -d $SEPAR -f 1) = $PARAM_1 ]
	then
            echo -n `sed "s/$str/$PARAM_1$SEPAR$PARAM_2/" -i $FILE_NAME`
	    FLAG_2=1
	fi
    done
    if [ $FLAG_2 = 0 ]
    then
        echo "$PARAM_1""$SEPAR""$PARAM_2" >> $FILE_NAME
    fi
}

del_func()
{
    if [ ! -e $FILE_NAME ]
    then
	echo "No base found : FILE $FILE_NAME" > /dev/stderr
	exit 1
    fi
    FLAG=0
    if [ $(echo $PARAM_1 | cut -c 1) = "$" ]
    then
	PARAM_1=`echo $PARAM_1 | cut -c 2-`
	FLAG=1

	VAR=`grep "$PARAM_1" $FILE_NAME`
	for str in $VAR
	do
            if [ $(echo $str | cut -d $SEPAR -f 1) = $PARAM_1 ]
	    then
	        PARAM_1=`echo $str | cut -d $SEPAR -f 2`
		FLAG=2
	    fi
	done

	if [ $FLAG = 1 ]
	then
	    echo "No such key : $PARAM_1" > /dev/stderr
	    exit 1
	fi

    fi
    FLAG=0
    if [ $PARAM_2 ] && [ $(echo $PARAM_2 | cut -c 1) = "$" ]
    then
	PARAM_2=`echo $PARAM_2 | cut -c 2-`
	FLAG=1
	VAR=`grep "$PARAM_2" $FILE_NAME`
	for str in $VAR
	do
            if [ $(echo $str | cut -d $SEPAR -f 1) = $PARAM_2 ]
	    then
	        PARAM_2=`echo $str | cut -d $SEPAR -f 2`
		FLAG=2
	    fi
	done

	if [ $FLAG = 1 ]
	then
	    echo "No such key : $PARAM_2" > /dev/stderr
	    exit 1
	fi
    fi
    VAR=`grep "$PARAM_1" $FILE_NAME`
    FLAG_2=0
    for str in $VAR
    do
	if [ $(echo $str | cut -d $SEPAR -f 1) = $PARAM_1 ]
	then
	    if [ -z $PARAM_2 ]
	    then
		echo -n `sed "s/$str/$PARAM_1$SEPAR/" -i $FILE_NAME`
	    else
		if [ $(echo $str | cut -d $SEPAR -f 2) = $PARAM_2 ]
		then
		    echo -n `sed "/$str/d" -i $FILE_NAME`
		fi
	    fi
	    FLAG_2=1
	fi
    done

    if [ $FLAG_2 = 0 ]
    then
	echo "No such key : $PARAM_1" > /dev/stderr
	exit 1
    fi
}

flush_func()
{

    if [ ! -e $FILE_NAME ]
    then
	echo "No base found : FILE $FILE_NAME" > /dev/stderr
	exit 1
    fi
    echo -n "" > $FILE_NAME
}

select_func()
{
    if [ $PARAM_2 != "null" ]
    then
	echo "Syntax error : Wrong parameters" > /dev/stderr
	exit 1
    fi

    if [ ! -e $FILE_NAME ]
    then
	echo "No base found : $FILE_NAME is incorrect" > /dev/stderr
	exit 1
    fi

    CLEFS=`cat $FILE_NAME`

    if [ $PARAM_1 ]
    then
	if [ `echo "$PARAM_1" | cut -c 1` = "$" ]
	then
	    ARG=`echo "$PARAM_1" | cut -c 2-`
	    ARG=`cat $FILE_NAME | grep $ARG | cut -d $SEPAR -f 2`
	else
	    ARG=$PARAM_1
	fi
    fi

    if [ $ARG = "null" ]
    then
	ARG=""
    fi

    for MATCH in $CLEFS
    do
	if [ $P = 1 ]
	then
	    VAL1=`echo $MATCH | cut -d $SEPAR -f 1`
	fi
	VAL=`echo $MATCH | cut -d $SEPAR -f 2`
	if [ $P = 1 ]
	then
	    if [ `echo $MATCH | cut -d $SEPAR -f 1 | grep "$ARG"` ]
	    then
		echo "$VAL1=$VAL"
	    fi
	else
	    if [ `echo $MATCH | cut -d $SEPAR -f 1 | grep "$ARG"` ]
	    then
		echo "$VAL"
	    fi
	fi
    done
 }

func_select()
{
    if [ $FUNC = "put" ] && [ $PARAM_1 != "$" ]
    then
	if [  $PARAM_2 = "null"  ]
	then
	    echo "Syntax error : Function $FUNC not found" > /dev/stderr
	    exit 1

	fi
	put_func
    elif [ $FUNC = "select" ] && [ $PARAM_1 != "$" ]
    then
	select_func
    elif [ $FUNC = "del" ]
    then
	if [ $PARAM_1 = "null" ]
	then
	    echo "Syntax error : Function $FUNC not found" > /dev/stderr
	    exit 1
	fi
	del_func
    elif [ $FUNC = "flush" ]
    then
	flush_func
    else
	echo "Syntax error : Function $FUNC not found" > /dev/stderr
	exit 1
    fi
    exit 0
}

main()
{
    if [ $1 ]
    then
	if [ $1 = '-k' ]
	then
	    P=1

	elif [ $1 = "-f" ] && [ $2 ]
	then
	    FILE=$2
	    F=1

	elif [ $2 ] && [ $3 ]
	then
	    FUNC=$1
	    PARAM_1=$2
	    PARAM_2=$3
	    if [ ! $4 ]
	    then
		func_select
	    else
		echo "Syntax error : Too much arguments"
		exit 1
	    fi
	elif [ $2 ]
	then
	    FUNC=$1
	    PARAM_1=$2
	    PARAM_2="null"
	    if [ ! $3 ]
	    then
		func_select
	    else
		echo "Syntax error : Too much arguments"
		exit 1
	    fi
	else
	    FUNC=$1
	    PARAM_1="null"
	    PARAM_2="null"
	    if [ ! $2 ]
	    then
		func_select
	    else
		echo "Syntax error : Too much arguments"
		exit 1
	    fi
	fi
    fi

    if [ $2 ] && [ $F = 0 ]
    then
	if [ $2 = "-f" ] && [ $3 ]
	then
	    FILE=$3
	    F=1

	elif [ $3 ] && [ $4 ]
	then
	    FUNC=$2
	    PARAM_1=$3
	    PARAM_2=$4
	    if [ ! $5 ]
	    then
		func_select
	    else
		echo "Syntax error : Too much arguments"
		exit 1
	    fi
	elif [ $3 ]
	then
	    FUNC=$2
	    PARAM_1=$3
	    PARAM_2="null"
	    if [ ! $4 ]
	    then
		func_select
	    else
		echo "Syntax error : Too much arguments"
		exit 1
	    fi
	else
	    FUNC=$2
	    PARAM_1="null"
	    PARAM_2="null"
	    if [ ! $3 ]
	    then
		func_select
	    else
		echo "Syntax error : Too much arguments"
		exit 1
	    fi
	fi
    else
	F=0
    fi
    if [ $3 ] && [ $F = 0 ]
    then
	if [ $3 = "-k" ]
	then
	    P=1

	elif [ $4 ] && [ $5 ]
	then
	    FUNC=$3
	    PARAM_1=$4
	    PARAM_2=$5
	    if [ ! $6 ]
	    then
		func_select
	    else
		echo "Syntax error : Too much arguments"
		exit 1
	    fi
	elif [ $4 ]
	then
	    FUNC=$3
	    PARAM_1=$4
	    PARAM_2="null"
	    if [ ! $5 ]
	    then
		func_select
	    else
		echo "Syntax error : Too much arguments"
		exit 1
	    fi
	else
	    FUNC=$3
	    PARAM_1="null"
	    PARAM_2="null"
	    if [ ! $4 ]
	    then
		func_select
	    else
		echo "Syntax error : Too much arguments"
		exit 1
	    fi
	fi
    else
	F=0
    fi
    if [ $4 ] && [ $5 ] && [ $6 ] && [ $F = 0 ]
    then
	FUNC=$4
	PARAM_1=$5
	PARAM_2=$6
	if [ ! $7 ]
	then
	    func_select
	else
	    echo "Syntax error : Too much arguments"
	    exit 1
	fi
    else
	F=0
    fi
    if [ $4 ] && [ $5 ] && [ $F = 0 ]
    then
	FUNC=$4
	PARAM_1=$5
	PARAM_2="null"
	if [ ! $6 ]
	then
	    func_select
	else
	    echo "Syntax error : Too much arguments"
	    exit 1
	fi
    else
	F=0
    fi
    if [ $4 ] && [ $F = 0 ]
    then
	FUNC=$4
	PARAM_1="null"
	PARAM_2="null"
	if [ ! $5 ]
	then
	    func_select
	else
	    echo "Syntax error : Too much arguments"
	    exit 1
	fi
    else
	echo "Syntax error : Usage ./bdsh.sh [OPTIONS] [FUNC] [KEY] [VAL]" > /dev/stderr
	exit 1
    fi
}

main $1 $2 $3 $4 $5 $6
