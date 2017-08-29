#!/bin/bash

path="$1"

cp tmp.sh $path/tmp_tmp.sh 
cp -r scripts $path/tmp_script
cp -r plot $path/tmp_plot

cd $path

chmod +x tmp_tmp.sh
./tmp_tmp.sh

rm -f -r $path/tmp_script $path/tmp_plot
rm -f $path/tmp_tmp.sh
