#! /bin/bash

touch analysis.txt
echo "-----------------" >> analysis.txt
echo "ANALYSIS - `date`" >> analysis.txt
echo "-----------------" >> analysis.txt
echo ""
echo "distance3" >> analysis.txt
echo "---------" >> analysis.txt
for x in $( seq 1 5 ); do
	echo "Running distance3 #$x..."
	./condor_measure.sh distance3 osmpoi.txt 41.7031036 -86.2391732 > /dev/null
	if [ $? -ne 0 ]; then
		echo "CONDOR ERROR"
		exit 1
	fi
	cat distance3.output | tail -n 1 >> analysis.txt
done

echo ""

echo "distance4a" >> analysis.txt
echo "----------" >> analysis.txt
for x in $( seq 1 5 ); do
	echo "Running distance4a #$x..."
	./condor_measure.sh distance4a osmpoi.txt 41.7031036 -86.2391732 > /dev/null
	if [ $? -ne 0 ]; then
		echo "CONDOR ERROR"
		exit 1
	fi
	cat distance4a.output | tail -n 1 >> analysis.txt
done

echo ""

echo "distance4b" >> analysis.txt
echo "----------" >> analysis.txt
for x in $( seq 1 5 ); do
	echo "Running distance4b #$x..."
	./condor_measure.sh distance4b osmpoi.txt 41.7031036 -86.2391732 > /dev/null
	if [ $? -ne 0 ]; then
		echo "CONDOR ERROR"
		exit 1
	fi
	cat distance4b.output | tail -n 1 >> analysis.txt
done

echo ""

echo "distance5" >> analysis.txt
echo "---------" >> analysis.txt
for x in $( seq 1 5 ); do
	echo "Running distance5 #$x..."
	./condor_measure.sh distance5 osmpoi.txt 41.7031036 -86.2391732 > /dev/null
	if [ $? -ne 0 ]; then
		echo "CONDOR ERROR"
		exit 1
	fi
	cat distance5.output | tail -n 1 >> analysis.txt
done


echo "Done."
echo "Output written to analysis.txt"
exit 0
