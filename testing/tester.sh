# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mans <yel-mans@1337.ma>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 15:27:02 by yel-mans          #+#    #+#              #
#    Updated: 2021/08/24 10:04:05 by yel-mans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

i=1
echo -n ">> EMTPY CHAR: "
read empty
echo -n ">> OBSTA CHAR: "
read obsta
echo -n ">> FULL CHAR: "
read full

echo -n ">> Do you want invalid maps also ? (0 for no): "
read invalid

rm -f ./maps/*
while [ $i -lt 100 ]
do

	x=$(( $RANDOM % 100 ));
	y=$(( $RANDOM % 100));
	density=$(( $RANDOM % 3));

	./mapper/mapper $((x)) $((y)) $((density)) $empty $obsta $full $invalid > tests/mapper_tests/map.txt;

	o1=$(./ours tests/mapper_tests/map.txt 2> err1.txt);
	
	o2=$(./bsq2 tests/mapper_tests/map.txt 2> err2.txt);

	if ! cmp --silent -- "err1.txt" "err2.txt"; then
		echo "files differ"
		exit 0

	
	if [[ $o1 == $o2 ]]; then
		echo TEST $i : PASSED;
	else
		echo TEST $i : FAILED;
		break;
	fi
	((i++))
done
