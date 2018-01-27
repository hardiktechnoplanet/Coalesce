/**********************************************************

  file       : coalesce.h

  last update: January 2017

  authors    : Jim Barkley (james@ekta.co), Hardik Garg (hardik@ekta.co), Vishesh Chanang (vishesh@ekta.co)

  description:  
    coalesce - this command line utility manipulates
    and compares point cloud data with CAD data

  license    : TBD

***********************************************************/

//todo do we actually need to put this in both .h and .cpp files?
using namespace std;


/* global structure for command line args */
struct globalArgs_t {
    char *inputFiles;               /* input files */
    char *outFileName;              /* output file */    
    int numInputFiles;              /* # of input files */
    bool input_f;                   /* flag for input */
    bool summary_f;                 /* flag for summary */
    bool convert_f;                 /* flag for convert */
    bool analyze_f;                 /* flag for analyze */
    bool verbose_f;                 /* flag for verbose */
} globalArgs;

/* The optString global tells getopt() which options we
 support, and which options have arguments. */
static const char *optString = "o:i:savh?";

/*
int no_of_points();
void point_cloud_summary();
void display_detailed_description();
bool isLoggingRequested(bool verbose_f);
bool isFileOpened(char filename);
*/

/**********************************************************

  function     : display_usage

  description  :  
    display program usage and exit    

  arguments    :
    @param const char *message - optional message to spit out before printing usage info

  return       : void

  precondition : none

  postcondition: displays usage message and exits with failure status

***********************************************************/
void display_usage( const char *message )
{

    if (NULL!=message) { cout << endl << message << endl << endl; }
    else { cout << endl; } 

    cout << "Usage: " << endl;
    cout << "  coa [options] -i <filename>" << endl << endl;
    cout << "coa - a tool to manipulate and compare point cloud and STEP data" << endl << endl;
    cout << "Options:" << endl;
    cout << "  -i, --input <filename>\t\tinput file(s)" << endl;
    cout << "  -o, --output <filename>\t\toutput file(s)" << endl;
    cout << "  -s, --summary\t\tprint out summary data about input file" << endl;
    cout << "  -a, --analyze\t\tprint out detailed analysis of input file" << endl;
    cout << "  -c, --convert\t\tconvert/compare file" << endl;
    cout << "  -v, --verbose\t\tprint out additional processing information at run time" << endl;
    cout << "  -h, --help\t\tprint out this message" << endl << endl;

    exit( EXIT_FAILURE );
}


/**********************************************************

  function     : no_of_points

  description  :  
    Count the number of points in the point cloud 

  arguments    : none

  return       : int (number of points)

  precondition : valid .asc file has been provided via the -i switch 

  postcondition: total number of points will be counted and returned. 

***********************************************************/
int no_of_points() {
  string data;
  int count = 0;
  if (globalArgs.verbose_f) {
    cout << "opening the input file: " << globalArgs.inputFiles << endl;
  } else {
    //noop (do nothing)
  }

  ifstream file(globalArgs.inputFiles);
  if(!file.is_open()) {
    cout<<"Error opening file"<<endl;
    return 0;
  }

  if (globalArgs.verbose_f) { 
    (cout << "Counting the number of points\n");
  } else {
    //noop (do nothing)
  }

  while(!file.eof()){
    getline(file,data);
    count++;
  }

  if (globalArgs.verbose_f) { 
    cout << "Closing the input file: " << globalArgs.inputFiles << endl;
  } else {
    //noop (do nothing)
  }

  file.close();

  //todo - worth stuffing this into a global?
  //todo return -1 on error
  return count;
}

/**********************************************************

  function     : point_cloud_summary

  description  :  
    Create the summary of the point cloud 

  arguments    : none

  return       : void

  precondition : none

  postcondition: prints out a variety of summary information

***********************************************************/
void point_cloud_summary() {
  if (globalArgs.verbose_f) {
    cout << "Preparing Summary ... " << endl;
  } else {
    //noop (do nothing)
  }

  //write header 
  cout <<"================================== SUMMARY ===================================" << endl << endl;

  //write total number of points
  cout << "Total number of points in the point cloud: "<< no_of_points() << endl;

  //todo output volumetric information

  //todo output processing time


  if (globalArgs.verbose_f) {
    cout << endl << "Done Writing Summary ... " << endl;
  } else {
    //noop (do nothing)
  }
}

/**********************************************************

  function: display_detailed_description

  description:  
    performs analysis on the input file

  arguments: none

  return: void

  precondition: a valid file has been specified via the -i command line argument

  postcondition: prints out all points in the cloud and total number of points

***********************************************************/
void display_detailed_description() {
  string data;
  int count = 0;
  ifstream file(globalArgs.inputFiles);
  if(!file.is_open()){
    cout<<"Error opening file"<<endl;
  }
  else{
    cout << "-------------------------------Analysis-------------------------------" << endl;
  }
  while(!file.eof()){
    getline(file,data);
    cout << data <<endl;
    count++;
  }
  file.close();
  cout << endl << "Total number of points: "<< count << endl;
}
