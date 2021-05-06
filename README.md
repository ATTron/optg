# OPTG
#### What is OPTG?
***
**O**rbit<br/>**P**ropagation<br/>and<br/>**T**iming<br/>**G**eometry File
*** 
## Resources
[Brief Description of OPTG](https://mars.nasa.gov/mgs/jpl-telem/optgex.html)   
[Documentation provided by NASA](https://pds.nasa.gov/data/mgs-m-rss-1-cru-v1.0/mors_0131/document/optg_sis.txt)

## Usage
This script will read in a valid OPTG file and return a CSV of all the events contained within the file.
``` bash
    ./OPTG <name-of-optg-file>
```

## Building for development
``` bash
    git clone https://github.com/attron/optg.git
```
``` bash
    mkdir optg_build && cd optg_build && cmake ../
```
``` bash
    cmake --build .
```
***
## Test Data
You can find available OPTG files from [JPL](https://naif.jpl.nasa.gov/pub/naif/).

An example output file using https://naif.jpl.nasa.gov/pub/naif/ORX/misc/optg/orx_optg_190201_190228_190225_od102_v1.txt 
can be found under the examples directory
