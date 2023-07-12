echo "Enter a number: "
read number
factorial=1
i=1
while ((i <= number)); do
 factorial=$((factorial * i))
 i=$((i + 1))
done
echo "The factorial of $number is $factorial."
