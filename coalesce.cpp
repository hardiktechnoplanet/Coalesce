/**********************************************************

  file       : coalesce.cpp

  last update: January 2017

  authors    : Jim Barkley (james@ekta.co), Hardik Garg (hardik@ekta.co), Vishesh Chanang (vishesh@ekta.co)

  description:  
    coalesce - this command line utility manipulates
    and compares point cloud data with CAD data

  license    : TBD

***********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <iostream>
#include <fstream>
#include <string>

#include "coalesce.h"


using namespace std;

/* coa supports the following command-line arguments:
 *
 * -i - input file 
 * -o outfile - write output to outfile instead of stdout
 * -s summary - print out summary 
 * -a analysis - print out analysis 
 * -v - be verbose; more -v means more diagnostics
 *
 */

/* main function to parse args and provide
   execution control structure depending on arguments
   provided */
int main( int argc, char *argv[] )
{
    int opt = 0;
    /* Initialize globalArgs before we get to work. */
    globalArgs.input_f = false;
    globalArgs.summary_f = false;
    globalArgs.convert_f = false;
    globalArgs.analyze_f = false;
    globalArgs.verbose_f = false;

    /* Process the arguments with getopt(), then * populate globalArgs. */
    opt = getopt( argc, argv, optString );
    while( opt != -1 ) {
      switch( opt ) {
            case 'i':
                globalArgs.input_f = true;
                globalArgs.inputFiles = optarg;
                break;

            case 'a':
                globalArgs.analyze_f = true;
                break;
/*
            case 'l':
                globalArgs.langCode = optarg;
                break;
*/

            case 'o':
                /* This generates an "assignment from
                 * incompatible pointer type" warning that
                 * you can safely ignore.
                 */
                globalArgs.outFileName = optarg;
                break;
            case 's':
                if(globalArgs.outFileName == NULL)
                      globalArgs.outFileName = "summary.txt";
                globalArgs.summary_f = true;
                break;
            case 'v':
                //globalArgs.verbosity++;
                globalArgs.verbose_f = true;
                break;

            case 'c':
                globalArgs.convert_f = true;
                break;


            case 'h':   /* fall-through is intentional */
            case '?':
                display_usage(NULL);
                break;

            default:

                /* You won't actually get here. */
                break;
        }

        opt = getopt( argc, argv, optString );
    }

    /* Check for input file */
    if(globalArgs.input_f == false) {
      display_usage("No input file provided. The program will exit.");
    }

    /* Get summary */
    if(globalArgs.summary_f == true || (globalArgs.convert_f == false && globalArgs.analyze_f == false)){
      point_cloud_summary();
    }

    /* Analysis */
    if(globalArgs.analyze_f == true){
      display_detailed_description();
    }


     return 0;
}

