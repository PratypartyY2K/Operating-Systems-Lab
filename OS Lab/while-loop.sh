i=1; n=5;
while [ $i -le 10 ]
do
echo "$n * $i = `expr $i \* $n`"
i=`expr $i + 1`
done

