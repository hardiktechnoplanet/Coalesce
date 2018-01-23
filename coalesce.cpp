/* coalesce - this command line utility manipulates
    and compares point cloud data with CAD data
 *
 * This application ...
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <cstring>

#include<iostream>
#include<fstream>
#include<string>


using namespace std;

struct globalArgs_t {
    int noIndex;                                /* -I option */
    char *langCode;                             /* -l option */
    const char *outFileName;    /* -o option */
    FILE *outFile;
    int verbosity;                              /* -v option */
    char **inputFiles;                  /* input files */
    int numInputFiles;                  /* number of input files */
} globalArgs;
int numInputFiles;                  /* # of input files */

static const char *optString = "Il:o:i:vh?";

//argc = argument count, argv=array that contains the argument
int main( int argc, char *argv[] )
{
    int opt = 0;
    int arg_count = 1;
    /* Initialize globalArgs before we get to work. */
    globalArgs.noIndex = 0;             /* false */
    globalArgs.langCode = NULL;
    globalArgs.outFileName = NULL;
    globalArgs.outFile = NULL;
    globalArgs.verbosity = 0;
    globalArgs.inputFiles = NULL;
    globalArgs.numInputFiles = 0;
    
    /* the below code finds the position of "-i" in the 
    argv[]. The arrary position is stored in Count. 
    Count+1 holds the file path*/
    cout<<"the value of argc: "<<argc<<endl;
    int Count;
	for (int i = 0; i < argc; ++i){
        char* instr=argv[i];
		cout << argv[i] << "\n";
        if (strcmp(instr,"-i") == 0)
		Count=i;
    }
    cout<<"the value of i: "<<Count<<endl;
    /* Process the arguments with getopt(), then
     * populate globalArgs.
     */

     /* Vishesh comment */
    opt = getopt( argc, argv, optString );
    while( opt != -1 ) {
        switch( opt ) {
              case 'i':
                  cout<<"goes into this"<<endl;
                  break;
            // case 'a':
            //     globalArgs.noIndex = 1; /* true */
            //     break;
            //
            // case 'l':
            //     globalArgs.langCode = optarg;
            //     break;
            //
            // case 'o':
            //     /* This generates an "assignment from
            //      * incompatible pointer type" warning that
            //      * you can safely ignore.
            //      */
            //     globalArgs.outFileName = optarg;
            //     break;
            //
            // case 'v':
            //     globalArgs.verbosity++;
            //     break;
            //
            // case 'h':   /* fall-through is intentional */
            // case '?':
            //     display_usage();
            //     break;
            //
            // default:
            //     /* You won't actually get here. */
            //     break;
         }

         opt = getopt( argc, argv, optString );
     }

    //globalArgs.inputFiles = argv + optind;
    //globalArgs.numInputFiles = argc - optind;

    //convert_document();
    void convert_document();
    string data;
    int count = 0;
    //specify the path here
    //D:\\EKTA\\Coalesce\\files\\SBD Nosecone.asc
    //ifstream file(argv[2]);
    ifstream file(argv[Count+1]);
	if(!file.is_open()){
      cout<<"Error opening file"<<endl;
      return 0;
    }
    while(!file.eof()){
      getline(file,data);
      count++;
    }
     cout<<count<<endl;
     return 0;
}


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

/* Display program usage, and exit.
 */
void display_usage( void )
{
    puts( "doc2html - convert documents to HTML" );
    /* ... */
    exit( EXIT_FAILURE );
}

/* Convert the input files to HTML, governed by globalArgs.
 */
void convert_document( void )
{
    /* ... */
}
