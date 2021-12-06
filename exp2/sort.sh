echo "Enter array size"
read n
echo "Enter array elements"
for (( i = 0; i < $n; i++ ))
do
read a[$i]
done

for (( i = 0; i < $n ; i++ ))
do
for (( j = $i; j < $n; j++ ))
do
if [ ${a[$i]} -gt ${a[$j]}  ]; then
temp=${a[$i]}
a[$i]=${a[$j]}
a[$j]=$temp
fi
done
done
echo -e "\nSorted Numbers "
for (( i=0; i < $n; i++ ))
do
echo -e ${a[$i]}
done