#!/bin/bash



if make; then
    ./sim 15 13 6 1
    mv output0.root res/FTFP/C-13.root

    ./sim 15 9 4 1
    mv output0.root res/FTFP/Be-9.root




    ./sim 15 56 26 0
    mv output0.root res/QGSP/Fe-56.root

    ./sim 15 17 8 0
    mv output0.root res/QGSP/O-17.root

    ./sim 15 13 6 0
    mv output0.root res/QGSP/C-13.root

    ./sim 15 9 4 0
    mv output0.root res/QGSP/Be-9.root

else
    echo "Compilation failed. TGFSIM will not run."
fi