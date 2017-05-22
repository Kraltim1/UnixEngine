sh testing/test_1.sh
echo "exit" >> testing/input.txt
./draw < testing/input.txt > output.txt
rm testing/input.txt