






/* coalesce - this command line utility manipulates
    and compares point cloud data with CAD data
 *
 * This application ...
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>


#include<iostream>
#include<fstream>
#include<string>


using namespace std;

/* doc2html supports the following command-line arguments:
 *
 * -I - don't produce a keyword index
 * -l lang - produce output in the specified language, lang
 * -o outfile - write output to outfile instead of stdout
 * -v - be verbose; more -v means more diagnostics
 * additional file names are used as input files
 *
 * The optString global tells getopt() which options we
 * support, and which options have arguments.
 */
struct globalArgs_t {
    int noIndex;                                /* -I option */
    char *langCode;                             /* -l option */
    const char *outFileName;    /* -o option */
    FILE *outFile;
    int verbosity;                              /* -v option */
    char *inputFiles;                  /* input files */
    int numInputFiles;                  /* # of input files */
    bool summary_f;                 /* flag for summary */
    bool convert_f;                 /* flag for convert */
    bool analyze_f;                 /* flag for analyze */
    bool verbose_f;                 /* flag for verbose */
} globalArgs;

static const char *optString = "o:i:savh?";

int no_of_points();
void point_cloud_summary();
void display_detailed_description();

/* Display program usage, and exit.
 */
void display_usage( void )
{
    puts( "coa - a tool to manipulate and compare point cloud and STEP data" );
    /* ... */
    exit( EXIT_FAILURE );
}

int main( int argc, char *argv[] )
{
    int opt = 0;

    /* Initialize globalArgs before we get to work. */
    globalArgs.noIndex = 0;             /* false */
    globalArgs.langCode = NULL;
    globalArgs.outFileName = NULL;
    globalArgs.outFile = NULL;
    globalArgs.verbosity = 0;
    globalArgs.inputFiles = NULL;
    globalArgs.numInputFiles = 0;
    globalArgs.summary_f = false;
    globalArgs.convert_f = false;
    globalArgs.analyze_f = false;
    globalArgs.verbose_f = false;

    /* Process the arguments with getopt(), then
     * populate globalArgs.
     */
    opt = getopt( argc, argv, optString );
    while( opt != -1 ) {
      switch( opt ) {
            case 'i':
                globalArgs.inputFiles = optarg;
                break;

            case 'a':
                globalArgs.analyze_f = true;
                break;

            case 'l':
                globalArgs.langCode = optarg;
                break;

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
                display_usage();
                break;

            default:

                /* You won't actually get here. */
                break;
        }

        opt = getopt( argc, argv, optString );
    }

    if(globalArgs.summary_f == true || (globalArgs.convert_f == false && globalArgs.analyze_f == false && globalArgs.verbose_f == false)){
      point_cloud_summary();
    }

    if(globalArgs.analyze_f == true){
      display_detailed_description();
    }
     return 0;
}

/* Count the number of points in the point cloud */
int no_of_points(){
  string data;
  int count = 0;
  ifstream file(globalArgs.inputFiles);
  if(!file.is_open()){
    cout<<"Error opening file"<<endl;
    return 0;
  }
  while(!file.eof()){
    getline(file,data);
    count++;
  }
  file.close();
  return count;
}

/* Create the summary of the point cloud */
void point_cloud_summary(){
  ofstream outfile (globalArgs.outFileName);
  if(outfile.is_open()){
    outfile <<"=========================SUMMARY=========================" << endl << endl;
    outfile << "Total number of points in the point cloud: "<<no_of_points() << endl;
    outfile.close();
  }
  else{
    cout << "Error. Unable to open file"<<endl;
  }
}

/* Print point cloud analysis(temporary) */
void display_detailed_description(){
  string data;
  int count = 0;
  ifstream file(globalArgs.inputFiles);
  if(!file.is_open()){
    cout<<"Error opening file"<<endl;
  }
  while(!file.eof()){
    getline(file,data);
    cout << data <<endl;
    count++;
  }
  file.close();
  cout << endl << "Total number of points: "<< count << endl;
}
