test 5 -le $# && echo "Number of args more than (or equal to) 5" || 
echo "Number of args less than 5"
a=1
until [ $1 -eq 0 ]
do
  echo "arg $a: $1"
  ((a++))
  shift 1
done
