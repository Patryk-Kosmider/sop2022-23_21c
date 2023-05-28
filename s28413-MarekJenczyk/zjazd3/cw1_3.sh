#!/bin/bash

if [[ $0 =~ \.sh$ ]]; then
        echo "Nazwa pliku posiada koncowke .sh"
else
        mv $0 $0.sh
fi

