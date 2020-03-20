//HERE

// **MEMORY LEAK - search
// gcc -o classify6 classify6.c



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include  "structures.h"
#include  "structures_svg.h"



int const   DATASET_SET_TO = 2;
bool const  FORCE_OUTPUT = false;


bool DATASET_BCD_TOGGLE = DATASET_SET_TO == 0;
bool DATASET_HEART_TOGGLE = DATASET_SET_TO == 1; 
bool DATASET_WDBC_TOGGLE = DATASET_SET_TO == 2;



float TRAINING_SET_RATIO = 0.7;
float ACCURACY = 0.7;

int DECIMALS;
int NUMBER_OF_DIMENSIONS;


bool SHOW_CLASSIFIER_SCORE = true;
bool SHOW_CLASSIFIER_OUTPUT = true;
bool USE_VOTE_CAP = true;
bool USE_INTERVAL_RATING = false;
bool USE_SAMPLESIZE_MIN = false;


char * DESKTOP = "/Users/macbook/desktop/";
char * DATA_PATH;// = "/Users/macbook/Desktop/opengl2/bcd.txt"; // ACCURACY(0.8f) >= 100% 
//char * DATA_PATH = "/Users/macbook/Desktop/opengl2/heart.txt"; // ACCURACY(0.8f) >= 100% 



//char * DATA_PATH = "/Users/macbook/Desktop/opengl2/iris.txt"; // ACCURACY(0.8f-0.9f) >= 100%
//char * DATA_PATH = "/Users/macbook/Desktop/opengl2/wine.txt"; // ACCURACY(0.8f-0.9f) >= 100% 
//char * DATA_PATH = "/Users/macbook/Desktop/opengl2/pen.txt"; // ACCURACY(0.8f) >= 100% 
//char * DATA_PATH = "/Users/macbook/Desktop/opengl2/wdbc.txt"; 

// NOT GOOD ??? // char * DATA_PATH = "/Users/macbook/Desktop/opengl2/glass.txt"; // ACCURACY(0.8f) >= 97%
char * VERSION = "1.2";
char * LOAD_PATH = "/Users/macbook/Desktop/opengl2/";
char * OUT_PATH =  "/Users/macbook/desktop/out.txt";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



void  FloatArray2InsertColEmpty(FloatArray2 * data, int col_pos);
void  FloatArrayOverwriteCol( FloatArray2 * floats , FloatArray * flt, int col );
void  Sort2AscColAndLast( FloatArray2 * segments, FloatArray2 * values_in_columns, int column, FloatArray3 * buffer3, FloatArray2 * buffer2, FloatArray * buffer1);
void  OutFloatArray2COLCol( char * title, FloatArray2 * cols, String * out  );
int   getClassCount( FloatArray2 * data, int class_column , FloatArray * bufferFA );
void  FloatArray2COLSplitToRatio( float test_ratio, FloatArray2 * data_in_col_1, FloatArray2 * data_in_col_2, FloatArray3 * buf3, FloatArray * buf1 );
void  BuildClassifer( FloatArray3 * tables, FloatArray2 * training_data, int number_of_dimensions, int number_of_classes, float join_ratio, FloatArray3 * memoryFA3, FloatArray3 * buf3B, String * out );
float ValidateClassifier( FloatArray3 * classifier, FloatArray2 * testing_data, int number_of_classes, FloatArray * buf  );
void  ConsolidateByClass(  FloatArray2 * consolidated, FloatArray2 * sorted_values  );
void  ConsolidateByValue(  FloatArray2 * consolidated, FloatArray2 * sorted_values, int number_of_classes, FloatArray * buf  );
void  JoinClassRatiosGreaterThan( FloatArray2 * intervals, FloatArray2 * floats , float ratio, FloatArray3 * buf3  );
void  KSplitRatio( FloatArray3 * splits, FloatArray2 * values, int K , int n_classes, FloatArray * buffer );
void  OutFloatArray2COLRow( char * title , FloatArray2 * data, String * out );
void  KFoldValidation(FloatArray3 * kfoldsplit, FloatArray3 * classify, FloatArray2 * data_by_col_train , FloatArray * scores, int number_of_dimensions, int number_of_classes, FloatArray3 * bufferFA3A, FloatArray3 * bufferFA3B ,  FloatArray * bufferFA1, String * out );
void  OutFA3C( FloatArray3 * cols, String * out  );
void  FA2CQuadraticDimensions( FloatArray2 * data_by_column );
void  GetClassPredictions( FloatArray * predictions, FloatArray3 * classifier, PointArray * data  );
void  exportStringSVG_FILEPATH( String * SVG, String * filename_buffer, char * FULL_FILEPATH );
void  SvgClassifier( String * svg, FloatArray * params, FloatArray2 * colors , FloatArray3 * classifier );
void  SvgDisplayParameters( FloatArray * params, float sizeX, float sizeY, float marginX, float marginY );
void  LineArrayColocatedPairsPreset( LineArray * lines, int dimensions, float scaleX, float scaleY,  FloatArray * bufferFA );
void  FA2GetColors( FloatArray2 * colors );
void  encodeSVG( FloatArray3 * k_fold_slices , FloatArray3 * classify, int row, char * filename );
void  FACountValues( FloatArray * counts, FloatArray * data, FloatArray * values_to_count );
void  FA2Histogram( FloatArray2 * histo, FloatArray2 * dat, int dimension_enum, int class_enum );
void  SVGHistogram( String * svg, FloatArray * histo_vals, FloatArray * histo_cnts  );
void  histogramMatchBins( FloatArray * val1,FloatArray * cnt1,FloatArray * val2,FloatArray * cnt2);
void  OutFloatArray3Table( char * title , FloatArray3 * data, String * out );
int   GetPredictedClass( FloatArray3 * classifications , int col, float val );
int   GetActualClass( FloatArray2 * values , int row );
void  GetPredictionVector( FloatArray * prediction_vector, FloatArray2 * prediction_vector_array, int number_of_classes, FloatArray * buf );
void  PatternsGet2V0( FloatArray2 * patterns, FloatArray2 * data, int number_of_dimensions , FloatArray2 * bufferFA2  );
void  PatternsGetSet2V0( FloatArray2 * patterns, FloatArray2 * data, int number_of_dimensions , FloatArray2 * bufferFA2 );
void  GetPredictionVectorAug( FloatArray * prediction_vector, FloatArray2 * prediction_vector_array, FloatArray2 * override, int number_of_classes, FloatArray * buf, FloatArray * actual_vector );

void StringOpenJSON( String * str );
void StringCloseJSON( String * str );
void StringAddJSONFieldArray2( String * str, FloatArray2 * data, char * name, char * f );
void StringAddJSONFieldArray( String * str, FloatArray * data, char * name, char * f );
  
FloatArray3 FLOATS,FLOATS2, FLOATS3, FLOATS4, FLOATS5,FLOATS6; 
String STRING1, STRING2, STRING3, STRING4;
StringArray STRINGS1, STRINGS2, STRINGS3, STRINGS4;
FloatArray3 ERROR_LOG;

void  PROGRAM();
void SET_DATA_FOR_BCD   ( bool toggle ){ if(toggle){ DATA_PATH = "/Users/macbook/Desktop/opengl2/bcd.txt"; NUMBER_OF_DIMENSIONS = 10; DECIMALS = 2;}}
void SET_DATA_FOR_HEART ( bool toggle ){ if(toggle){ DATA_PATH = "/Users/macbook/Desktop/opengl2/heart.txt"; NUMBER_OF_DIMENSIONS = 14; DECIMALS = 3;} }
void SET_DATA_FOR_WDBC  ( bool toggle ){ if(toggle){ DATA_PATH = "/Users/macbook/Desktop/opengl2/wdbc.txt"; NUMBER_OF_DIMENSIONS = 32 - 1; DECIMALS = 5;} }

void FORMAT_BCD( bool toggle, FloatArray2 * col_data, StringArray * class_names, FloatArray * indices, int * number_of_dimensions,  FloatArray * buf1, StringArray * buf2 ){
  if( toggle ){ 
    FA2CRmvCol( col_data, 0 ); 
    number_of_dimensions[0]--;
    
    StringArrayRemoveIndices( class_names , indices ); 
    
    FloatArrayReset( buf1 );
    StringArrayReset( buf2 );
    
    StringArray * class_names_set = buf2;
    FloatArray * enumerated_class_names = buf1;
    StringArrayGetUnique( class_names_set , class_names );
    FloatArrayEnumerateAlphas( enumerated_class_names , class_names, class_names_set ); 
    
    FloatArray2Add( col_data, enumerated_class_names ); 
    
    printf("DATASET: Breast Cancer Prediction\n");
  }
}

void FORMAT_HEART( bool toggle, FloatArray2 * col_data, FloatArray2 * buf1 ){
  if( toggle ){ 
    int F = col_data -> length - 1;
    FloatArray2Reset( buf1 );
    FloatArray * targets = FloatArray2Next( buf1 ); 
    FloatArray * buffer = FloatArray2Next( buf1 ); 
    
    FA2CGetCol( targets, col_data, F );
    FloatArray2RemoveIndex( col_data, F , buffer );
    
    FAEnumerate( targets );
    FloatArray2Add( col_data , targets );
    printf("DATASET: Heart Disease Prediction\n");
  }
}


void FORMAT_WDBC( bool toggle, FloatArray2 * col_data, StringArray * names, int * number_of_dimensions,  StringArray * bufSA, FloatArray * buf1 ){
  if( toggle ){ 
    FA2CRmvCol( col_data, 0 ); 
    number_of_dimensions[0]--;
    
    StringArrayReset( bufSA ); 
    FloatArrayReset(  buf1 ); 
    StringArray   * class_names_set = bufSA;
    FloatArray    * enumerated_class_names = buf1;
    
    StringArrayGetUnique( class_names_set , names );
    FloatArrayEnumerateAlphas( enumerated_class_names , names, class_names_set ); 
    
    FloatArray2Add( col_data, enumerated_class_names ); 
    PrintSection('-', 50 );
    printf("DATASET: Wisconsin Breast Cancer Prediction\n");
    
    
  }
  
  
}

int main( int argc, char **argv ){
  
  SET_DATA_FOR_BCD(   DATASET_BCD_TOGGLE );
  SET_DATA_FOR_HEART( DATASET_HEART_TOGGLE ); 
  SET_DATA_FOR_WDBC(  DATASET_WDBC_TOGGLE );
  
  PROGRAM( DATA_PATH ); 
  
  
  
  
  
  return  0;
}




void GetPredictionVectorArray( FloatArray2 * prediction_vector_array, FloatArray3 * classify, FloatArray2 * data_by_col_test );
void GetVectorPredictionClassTotals( FloatArray2 * votes, FloatArray2 * prediction_vector, int number_of_classes );
void SortPredictionVectorArray( FloatArray2 * prediction_vector_array_sorted, FloatArray2 * prediction_vector_array, int number_of_dimensions, FloatArray3 * index_hier0, FloatArray3 * index_hier1 );
void FloatArray3AddView( FloatArray3 * to, FloatArray2 * from );


void FAGetIndicesMatchingValuePair(FloatArray * indices, FloatArray * one,  FloatArray * two,int val1, int val2 ){
  int L = one->length, L2, prd, tgt;
  for(int i = 0 ; i < L; i++ ){
    prd = one->get[i];
    tgt = two->get[i];
    if( prd == val1 && tgt == val2 ){
        FloatArrayAdd( indices, i ); 
    }
  }
}
//SortBy_FN_TN_TP_FP
void GetIndices_FN_TN_TP_FP( FloatArray * fn, FloatArray * tn, FloatArray * tp, FloatArray * fp, FloatArray * pred_vctr, 
                             FloatArray * actl_vctr, bool VERBOSE ){
  //bool VERBOSE = true;
  int count;
  
  FAGetIndicesMatchingValuePair(fn, pred_vctr, actl_vctr, 0, 1 );
  FAGetIndicesMatchingValuePair(tn, pred_vctr, actl_vctr, 0, 0 );
  FAGetIndicesMatchingValuePair(fp, pred_vctr, actl_vctr, 1, 0 );
  FAGetIndicesMatchingValuePair(tp, pred_vctr, actl_vctr, 1, 1 );
  
  if(VERBOSE){
      printf("FN: ");FAPrintL( fn ); 
      printf("TN: ");FAPrintL( tn ); 
      printf("FP: ");FAPrintL( fp ); 
      printf("TP: ");FAPrintL( tp ); 
      count = FACountCommonElements( fn, tn ); 
      printf("elements in common (fn -> tn_set): %i\n", count );
      count = FACountCommonElements( tn , fn ); 
      printf("elements in common (fn -> tn_set): %i\n", count );
      
      count = FACountCommonElements( fp, tp ); 
      printf("elements in common (fn -> tn_set): %i\n", count );
      count = FACountCommonElements( tp , fp); 
      printf("elements in common (fn -> tn_set): %i\n", count );
      
      PrintSection( '-', 30);
      printf("indices_FN: ");FAPrintL( fn ); 
      printf("indices_TN: ");FAPrintL( tn ); 
      printf("indices_FP: ");FAPrintL( fp ); 
      printf("indices_TP: ");FAPrintL( tp ); 
  }
}




void FA2GetByIndices( FloatArray2 * selected_data, FloatArray2 * data, FloatArray * indices ){
  bool VERBOSE = false;
  int i, index, L = indices->length;
  for(i = 0 ; i < L; i++ ){
    index = indices->get[i];
    FloatArray2Add( selected_data, &data->get[index] ); 
  } 
  if(VERBOSE){ printf("selected_data: "); FA2PrintL( selected_data );  }
}

void GetData_FN_TN_TP_FP( FloatArray2 * fn, FloatArray2 * tn, FloatArray2 * tp, FloatArray2 * fp,
                          FloatArray * fn_indices, FloatArray * tn_indices, FloatArray * tp_indices, FloatArray * fp_indices, 
                          FloatArray2 * data, bool VERBOSE  ){
      
      //bool VERBOSE = false;
      
      FA2GetByIndices(fn,data,  fn_indices); 
      FA2GetByIndices(tn,data,  tn_indices); 
      FA2GetByIndices(tp,data,  tp_indices); 
      FA2GetByIndices(fp,data,  fp_indices);
      
      int count;
      if(VERBOSE){
        
        count = FA2CountCommonElements( fn, tn ); 
        printf("elements in common (fals_neg:true_neg): %i\n", count );
        count = FA2CountCommonElements( tn , fn); 
        printf("elements in common (true_neg:fals_neg): %i\n", count );
        
        count = FA2CountCommonElements( tp , fp); 
        printf("elements in common (true_pos:fals_pos): %i\n", count );
        
        count = FA2CountCommonElements( fp , tp); 
        printf("elements in common (fals_pos:true_pos): %i\n", count );
      }
}

void GetData_CommonValues( FloatArray2 * common_subarrays, FloatArray2 * one, FloatArray2 * two ){
  FloatArray *fa,*fb;
  bool eq;
  int L, L2, i;
  L = one->length, L2 = two -> length;
  for(int i = 0 ; i < L; i++ ){
    fa = &one->get[i];
    for(int j = 0 ; j < L2; j++ ){
      fb = &two->get[j];
      eq = FAEqual( fa, fb ); 
      if( eq ){
        FloatArray2Add( common_subarrays , fa );
        break;
      }
    }
  }
}

void RmvData_CommonValuesOf_FNTN_AND_TPFP( FloatArray2 * fn, FloatArray2 * tn, FloatArray2 * fp,FloatArray2 * tp, FloatArray2 * common_subarrays, 
                                           FloatArray2 * buffer, bool VERBOSE ){
  
  //bool VERBOSE = true;
  int count;
  GetData_CommonValues( common_subarrays, fn, tn ); 
  FA2RmvValues0( fn, common_subarrays , buffer );
  FA2RmvValues0( tn, common_subarrays , buffer );
  
  FloatArray2Reset( common_subarrays );
  GetData_CommonValues( common_subarrays, fp, tp ); 
  FA2RmvValues0( fp, common_subarrays , buffer );
  FA2RmvValues0( tp, common_subarrays , buffer );
  
  if(VERBOSE ){
      count = FA2CountCommonElements( fn, tn ); 
      printf("elements in common (fals_neg:true_neg): %i\n", count );
      count = FA2CountCommonElements( tn , fn); 
      printf("elements in common (true_neg:fals_neg): %i\n", count );
      count = FA2CountCommonElements( fp, tp ); 
      printf("elements in common (fals_neg:true_neg): %i\n", count );
      count = FA2CountCommonElements( tp , fp); 
      printf("elements in common (true_neg:fals_neg): %i\n", count );
  }
}

void GetSetsOfPatterns( FloatArray2 * fn_paterns_set, FloatArray2 * tn_paterns_set, FloatArray2 * fp_paterns_set, FloatArray2 * tp_paterns_set, 
                       FloatArray2 * fals_neg, FloatArray2 * true_neg, FloatArray2 * fals_pos, FloatArray2 * true_pos,
                       int number_of_dimensions, FloatArray2 * bufFA2,
                       bool VERBOSE
                      ){
  
 //bool VERBOSE = true;
 int count; 
  PatternsGetSet2V0( fn_paterns_set, fals_neg, number_of_dimensions,  bufFA2 );
  PatternsGetSet2V0( tn_paterns_set, true_neg, number_of_dimensions,  bufFA2 );
  PatternsGetSet2V0( fp_paterns_set, fals_pos, number_of_dimensions,  bufFA2 );
  PatternsGetSet2V0( tp_paterns_set, true_pos, number_of_dimensions,  bufFA2 );
  if( VERBOSE ){
    FA2PrintL( fn_paterns_set );
    FA2PrintL( tn_paterns_set );
    FA2PrintL( fp_paterns_set );
    FA2PrintL( tp_paterns_set );
    count = FA2CountCommonElements( fn_paterns_set, tn_paterns_set ); 
    printf("elements in common (fn_paterns_set:tn_paterns_set): %i\n", count );
    count = FA2CountCommonElements( tn_paterns_set , fn_paterns_set); 
    printf("elements in common (tn_paterns_set:fn_paterns_set): %i\n", count );
    count = FA2CountCommonElements( fp_paterns_set, tp_paterns_set ); 
    printf("elements in common (fn_paterns_set:tn_paterns_set): %i\n", count );
    count = FA2CountCommonElements( tp_paterns_set , fp_paterns_set); 
    printf("elements in common (tn_paterns_set:fn_paterns_set): %i\n", count );
  }
}


void GetData_ValuesUniqueToA( FloatArray2 * unique_patterns_of_one, FloatArray2 * paterns_set_A, FloatArray2 * patterns_set_B ){
  int count;
  int i, j , L, L2;
  bool eq;
  FloatArray * fa, * fb;
  L = paterns_set_A->length;
  L2 = patterns_set_B->length;
  count = 0;
  int precount;
  for(i = 0 ; i < L; i++ ){
    fa = &paterns_set_A->get[i];
    precount = count;
    for(j = 0 ; j < L2; j++ ){
      fb = &patterns_set_B->get[j];
      eq = FAEqual( fa, fb ); 
      if(eq) count++;
    }
    if( precount == count ){
      FloatArray2Add( unique_patterns_of_one , fa ); 
    }
  }
}


void GetData_GetPatternsUniqueTo_FN_TN_TP_FP( FloatArray2 * fn_unique, FloatArray2 * fp_unique, FloatArray2 * tn_unique, FloatArray2 * tp_unique,
                                              FloatArray2 * fn_paterns_set,FloatArray2 * tn_paterns_set,FloatArray2 * fp_paterns_set,FloatArray2 * tp_paterns_set,
                                              bool VERBOSE
                                                ){
  //bool VERBOSE = true;
  int count;
  GetData_ValuesUniqueToA( fn_unique, fn_paterns_set, tn_paterns_set );
  GetData_ValuesUniqueToA( tn_unique, tn_paterns_set, fn_paterns_set );
  GetData_ValuesUniqueToA( fp_unique, fp_paterns_set, tp_paterns_set );
  GetData_ValuesUniqueToA( tp_unique, tp_paterns_set, fp_paterns_set );
  
  if( VERBOSE ){
      count = FA2CountCommonElements( fn_unique, tn_paterns_set ); 
      printf("elements in common (fn_unique : tn_paterns_set): %i\n", count );
      count = FA2CountCommonElements( tn_unique, fn_paterns_set ); 
      printf("elements in common (tn_unique : tn_paterns_set): %i\n", count );
      
      count = FA2CountCommonElements( fp_unique, tp_paterns_set ); 
      printf("elements in common (fp_unique : tp_paterns_set): %i\n", count );
      count = FA2CountCommonElements( tp_unique, fp_paterns_set ); 
      printf("elements in common (tp_unique : fp_paterns_set): %i\n", count );
  }

}

void GetPredictionVectorAugmented( FloatArray * prediction_vector , FloatArray * actual_vector , FloatArray2 * prediction_vector_array, 
          FloatArray2 * false_neg, FloatArray2 * false_pos, FloatArray2 * bufFA2, String * data_out, bool VERBOSE, bool temp ){
  
  FloatArray  BUFP; FloatArray * bufP = &BUFP; FloatArrayConstr( bufP );
  FloatArray  BUFN; FloatArray * bufN = &BUFN; FloatArrayConstr( bufN );
  FloatArray2 FPS; FloatArray2 * fps = &FPS; FloatArray2Constr( fps );  // TEMP DELETE OK
  FloatArray2 FNS; FloatArray2 * fns = &FNS; FloatArray2Constr( fns );  // TEMP DELETE OK
  
  
  
  //bool VERBOSE = true;
  bool MAX_CLASS_IS_NONE, eq;
  
  int CLASS_1 = 0, CLASS_2 = 1, CLASS_NULL = 9;
  
  FloatArray * fa, * fb;
  if(VERBOSE)PrintSection( '-', 30);
  int p, q, v;
  int i, j, L, L2;
  L = prediction_vector_array->length;
  int NO_VAL = 2;
  int c1,c2,v1,v2,v3,v4;
  int paterns_found;
  for(int i = 0 ; i < L; i++ ){
    
    // 1. pet inital prediction 
    fa = &prediction_vector_array->get[i];
    p = FAMostCommonValueIndexOfNum3( fa , CLASS_1, CLASS_2, CLASS_NULL, bufFA2 ); 
    MAX_CLASS_IS_NONE = p == NO_VAL;
    if(MAX_CLASS_IS_NONE) p = FASecondMostCommonValueIndexOfNum3( fa , CLASS_1, CLASS_2, CLASS_NULL, bufFA2 ); 
    q = actual_vector->get[i];
    if(VERBOSE){
        FAPrintf( fa, "%.0f" ); 
        printf(" {%i}!", p ); 
        if(MAX_CLASS_IS_NONE) printf("!");
        printf("\t[%i]", (int)  q ); 
    }
    v = p;
    
    FloatArrayReset( bufN ); 
    FloatArrayReset( bufP );
    
    // 2. handle possible false negatives
    if( p == 0 && q == 1){ 
      paterns_found = 0;
      L2= false_neg->length;
      for( j = 0 ; j < L2; j++ ){
        fb = &false_neg->get[j];
        c1 = fb->get[0];
        c2 = fb->get[1];
        v1 = fb->get[2];
        v2 = fb->get[3];
        
        v3 = fa->get[c1];
        v4 = fa->get[c2];
        eq = v1 == v3 && v2 == v4;
        if(eq){ paterns_found++;}
        if(eq){
          
          FloatArrayAdd( bufN , j );
          
          
          
        }
      }
      if(paterns_found){
        v = 1;
        if(VERBOSE)printf("\t->\t{%i}\t(%i)", v, paterns_found);
        FloatArray2Add( fns , bufN ); 
      } else{
        if(VERBOSE)printf("\t->\t(!)");
        
      }
      if(VERBOSE)printf("\n");
    } else
      
       
      // 3. handle possible false positives
    if( p == 1 && q == 0){ 
        paterns_found = 1;
        L2= false_pos->length;
        for( j = 0 ; j < L2; j++ ){
          fb = &false_pos->get[j];
          c1 = fb->get[0];
          c2 = fb->get[1];
          v1 = fb->get[2];
          v2 = fb->get[3];
          
          v3 = fa->get[c1];
          v4 = fa->get[c2];
          eq = v1 == v3 && v2 == v4;
          if(eq) { paterns_found++;}
          if(eq) { 
            FloatArrayAdd( bufP , j );
          }
          
          
        }
        if(paterns_found){
          v = 0;
          if(VERBOSE)printf("\t->\t{%i}\t(%i)", v, paterns_found);
           
        } else{
          if(VERBOSE)printf("\t->\t(!)");
          
        }
        if(VERBOSE)printf("\n");
      }
      

      else {
        if(VERBOSE)printf("\n");
      }
      
      FloatArray2Add( fps , bufP );
      FloatArray2Add( fns , bufN );
      //5. add in the resultant vote
      FloatArrayAdd( prediction_vector, v );
  }
  
  if(temp){
    StringAppendChar( data_out, ',');  StringAddJSONFieldArray2(data_out, fps , "TestFalsePositiveIndices", "%.0f"); 
    StringAppendChar( data_out, ',');  StringAddJSONFieldArray2(data_out, fns , "TestFalseNegativeIndices", "%.0f"); 
  }
}


// StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, prediction_vector_array , "TestDataPredictionVectors", "%.0f"); 
void KRecombine( FloatArray3 * data_train_all, FloatArray3 * data_test_all, FloatArray3 * k_split_data, int K ){
  
  bool VERBOSE = false;
  FloatArray2 * data_by_col_train, * data_by_col_test;
  int columns = k_split_data->get[0].length;
  int parts   = k_split_data->length;
  
  int i , j;
  for( int i = 0; i < K ; i++ ){
    data_by_col_train = & data_train_all ->get[i];
    data_by_col_test  = & data_test_all  ->get[i];
    FloatArray2Initialize2D1(data_by_col_train, columns );
    FloatArray2Initialize2D1(data_by_col_test, columns );
    if(VERBOSE)printf("selecting traintest(%i)\n", i );
    for( int j = 0; j < parts ; j++ ){
      if(VERBOSE)printf("\tslice(%i)\n", j );  
      //if(i == j) printf("(!)");
      //printf("\n");
      FloatArray2 * pieces = &k_split_data->get[j];
      FloatArray2 * selected_data = data_by_col_train;
      if(i == j) selected_data = data_by_col_test;
      for( int k = 0 ; k < columns; k++ ){
        FloatArray * piece = &pieces->get[k];
        if(VERBOSE)FAPrintf( piece , "%.0f");  
        if(VERBOSE)if(i == j) printf("(!)");
        if(VERBOSE)printf("\n");
        
        FloatArray * col = &selected_data->get[k];
        //printf("(%i)[%i]\n", k, selected_data->length );
        FloatArrayCopyToFrom( col, piece );
      }
      
    }
  }
}
void BuildClassifier2( FloatArray4 * classifiers, int * number_of_classes, FloatArray3 * data_train_all,  FloatArray3 * data_test_all, int number_of_dimensions, int K, FloatArray4 * bufFA4  ){
  
  bool VERBOSE = false;
  
  ////////////////////////////////////////////////////////////////////
  // IMPORT DATA OPEN MEMORY
  ////////////////////////////////////////////////////////////////////
  
  float ratio_of_trainset, ratio_of_testset;
  
  // initialize & instantiate
  FloatArray2 COPY;                   FloatArray2Constr( &COPY );  
  FloatArray2 SORTED;                 FloatArray2Constr( &SORTED );  
  FloatArray2 GRP_CLASS;              FloatArray2Constr( &GRP_CLASS );  
  FloatArray2 GRP_VALS;               FloatArray2Constr( &GRP_VALS );  
  FloatArray2 INTERVALS;              FloatArray2Constr( &INTERVALS );  

  // set to pointer 
  FloatArray2 * training_data_copy        = &COPY;
  FloatArray2 * sort2d_val_cls            = &SORTED;
  FloatArray2 * consolidated_cls          = &GRP_CLASS;
  FloatArray2 * consolidated_vals         = &GRP_VALS;
  FloatArray2 * intervals                 = &INTERVALS;
  
  // clear buffers
  FloatArray4Reset( bufFA4 );

  
  // set pointer pointers
  FloatArray3 * bufFA3          = FloatArray4Next( bufFA4 );
  FloatArray3 * bufFA3_sub      = FloatArray4Next( bufFA4 );
  FloatArray3 * classify        = FloatArray4Next( bufFA4 );
  FloatArray3 * split_data      = FloatArray4Next( bufFA4 );
  FloatArray2 * bufFA2          = FloatArray3Next( bufFA3_sub );
  FloatArray2 * bufFA2_sub      = FloatArray3Next( bufFA3_sub );
  FloatArray  * bufFA1          = FloatArray2Next( bufFA2_sub );
  
  FloatArray2 * data_by_col_train = &data_train_all ->get[0];
  FloatArray2 * data_by_col_test  = &data_test_all  ->get[0];
  ////////////////////////////////////////////////////////////////////
  // get class count
  ////////////////////////////////////////////////////////////////////
  int index_of_class_column = data_by_col_train -> length - 1;
  number_of_classes[0] = getClassCount( data_by_col_train , index_of_class_column , bufFA1 );
  int classes_count = number_of_classes[0];
  ////////////////////////////////////////////////////////////////////
  // Split into Train Test 
  ////////////////////////////////////////////////////////////////////
  
  ////////////////////////////////////////////////////////////////////
  // Handle K
  ////////////////////////////////////////////////////////////////////
  // PATH A
  bool has_K_split = K != -1 ;
  if(  has_K_split ){ 
    FloatArray2CopyToFrom2( training_data_copy, data_by_col_train );
    KSplitRatio( split_data, training_data_copy, K , classes_count, bufFA1 ); //FA3CPrintfln( split_data, "%.0f" ); 
    FloatArray2Reset( data_by_col_train ); 
    FloatArray2Reset( data_by_col_test );   
    KRecombine( data_train_all, data_test_all, split_data, K ); 

    
  } 
  // PATH B
  else {
    ratio_of_trainset = TRAINING_SET_RATIO;
    ratio_of_testset = 1 - ratio_of_trainset;
    FloatArray2 * data_selected = data_by_col_train;//data_by_col_test;
    FloatArray2COLSplitToRatio( ratio_of_testset, data_by_col_train, data_by_col_test, bufFA3, bufFA1 ); 
    K = 1;
  }
  
  
  
 
  
  
  ////////////////////////////////////////////////////////////////////
  // Build Classifier
  ////////////////////////////////////////////////////////////////////
  bool is_class_identifer_column;
  int current_dimension, actual_column; 
  int total = 0, correct = 0;
  index_of_class_column = data_by_col_train -> length;
  
  int i , j , k;  
  
  
 
  for( i = 0 ; i < K; i++ ){
 
      data_by_col_train = &data_train_all->get[i];
      data_by_col_test  = &data_test_all->get[i];
        
        
      for( j = 0 ; j < number_of_dimensions; j++ ){ // 2; i++){ number_of_dimensions
          
          current_dimension = j;
          //printf("current dimension: %i\n", j );
          actual_column = current_dimension > index_of_class_column ? current_dimension + 1 : current_dimension;
          is_class_identifer_column = current_dimension == index_of_class_column;
          
          if(is_class_identifer_column) continue;
          FloatArrayReset( bufFA1 ); 
        
          FloatArray2Reset( training_data_copy ); 
          
          
          
          
          
          FloatArray2CopyToFrom( training_data_copy, data_by_col_train , bufFA1);
          
          ////////////////////////////////////////////////////////////////////
          // show which table is being built
          //////////////////////////////////////////////////////////////////// 
          FloatArray2Reset( sort2d_val_cls ); 
          Sort2AscColAndLast( sort2d_val_cls, training_data_copy, current_dimension, bufFA3, bufFA2, bufFA1 ); 
          
          if(VERBOSE)PrintSection( '-', 50 );
          if(VERBOSE)FA2Printfln( sort2d_val_cls, "%3.2f " );
          
          
          
          
          
          ////////////////////////////////////////////////////////////////////
          // conslidate values 
          //////////////////////////////////////////////////////////////////// 
          FloatArray2Reset( consolidated_cls );
          ConsolidateByClass( consolidated_cls, sort2d_val_cls);
          
          
          
          
          
          if(VERBOSE)PrintSection( '-', 50 );
          if(VERBOSE)FA2Printfln( consolidated_cls, "%3.2f " );
          
          ////////////////////////////////////////////////////////////////////
          // conslidate by value, class 
          //////////////////////////////////////////////////////////////////// 
          FloatArray2Reset( consolidated_vals );
         
         
         
         
         
         
         
          ConsolidateByValue( consolidated_vals, consolidated_cls, *number_of_classes, bufFA1 );
 
       
          if(VERBOSE)PrintSection( '-', 50 );
          if(VERBOSE)FA2Printfln( consolidated_vals, "%3.2f " );
          
          ////////////////////////////////////////////////////////////////////
          // conslidate by value, class 
          //////////////////////////////////////////////////////////////////// 
          
          FloatArray2Reset( intervals );
          
          JoinClassRatiosGreaterThan( intervals, consolidated_vals , ACCURACY , bufFA3 );
          
          if(VERBOSE)PrintSection( '-', 50 );
          if(VERBOSE)FA2Printfln( intervals, "%3.2f " );
           
          
          FloatArray3Add( classify , intervals );
          
      }
      
      
      FloatArray4Add( classifiers, classify ); 
      
      
  }
  

  ////////////////////////////////////////////////////////////////////
  // free mem
  ////////////////////////////////////////////////////////////////////
  FloatArray2Free(training_data_copy);
  FloatArray2Free(sort2d_val_cls);
  FloatArray2Free(consolidated_cls);
  FloatArray2Free(consolidated_vals);
  FloatArray2Free(intervals);
  
  
  
}





float UseClassifier( int k, FloatArray4 * classifiers, FloatArray3 * train_by_col_all, FloatArray3 * test_by_col_all, FloatArray2 * prediction_vector_array, 
                    FloatArray2 * fals_neg, FloatArray2 * true_neg, FloatArray2 * true_pos, FloatArray2 * fals_pos, FloatArray2 * common, 
                    FloatArray2 * fn_paterns_set, FloatArray2 * tn_paterns_set, FloatArray2 * fp_paterns_set, FloatArray2 * tp_paterns_set,
                    FloatArray2 * fn_unique, FloatArray2 * tn_unique, FloatArray2 * fp_unique, FloatArray2 * tp_unique, FloatArray2 * bufFA2,
                    FloatArray * indices_FN, FloatArray * indices_TN, FloatArray * indices_FP, FloatArray * indices_TP, FloatArray * bufFA1,
                    FloatArray * actual_vector, FloatArray * prediction_vector, int number_of_classes, int number_of_dimensions, bool VERBOSE ){
  
  
  String STRING;
  String * str = &STRING;
  StringConstr( str, 1000 );
  
  StringAppendString2( str, "function getObject(){ return "); 
  StringOpenJSON( str ); 
  
  

  
  
  
  bool V = VERBOSE;
  FloatArray3 * classify;
  
  // set pointers
  classify = &classifiers->get[k];
  FloatArray2 * data_by_col_test          = &train_by_col_all ->get[k];// 
  FloatArray2 * data_by_col_train         = &test_by_col_all  ->get[k];// ;
  
  ////////////////////////////////////////////////////////////////////
  // CHECK RESULTS OF CLASSIFIER
  ////////////////////////////////////////////////////////////////////
  
  // instantiate
  FloatArray2 * selected_data            = data_by_col_train;
  
  ////////////////////////////////////////////////////////////////////
  // GET SELECTED TARGET VECTORS
  ////////////////////////////////////////////////////////////////////
  int f = selected_data->length - 1;
  FloatArrayReset( actual_vector );
  FloatArrayCopyToFrom( actual_vector, &selected_data->get[f] ); 
  
  ////////////////////////////////////////////////////////////////////
  // GET PREDICTION VECTOR
  ////////////////////////////////////////////////////////////////////
  FloatArray2Reset( prediction_vector_array ); FloatArrayReset( prediction_vector );
  GetPredictionVectorArray( prediction_vector_array, classify, selected_data ); 
  GetPredictionVector( prediction_vector, prediction_vector_array, number_of_classes, bufFA1 );
  
  StringAddJSONFieldArray2(str, prediction_vector_array , "PredictionVectors", "%.0f"); 
  StringAppendChar( str, ','); StringAddJSONFieldArray(str, prediction_vector , "PredictionVector", "%.0f");
  StringAppendChar( str, ','); StringAddJSONFieldArray(str, actual_vector , "TargetVector", "%.0f"); 
  
  //FA2Printfln( prediction_vector_array , "%.0f ");
  //FAPrintfln( prediction_vector , "%.0f ");
  
  ////////////////////////////////////////////////////////////////////
  // GET SIMILARITY
  ////////////////////////////////////////////////////////////////////
  float old_training_similarity = FASimilarityRatio( prediction_vector, actual_vector ); 
  if(VERBOSE)printf("T:%0.2f\n", old_training_similarity );
  
  ////////////////////////////////////////////////////////////////////
  // free mem
  ////////////////////////////////////////////////////////////////////
  // none
  
  
  ////////////////////////////////////////////////////////////////////
  // FIND PATTERNS IN FALSE POSITIVE && TRUE NEGATIVE
  //////////////////////////////////////////////////////////////////// 
  
  ////////////////////////////////////////////////////////////////////
  // ALLOCATE MEMORY
  ////////////////////////////////////////////////////////////////////
  
  
  
  ////////////////////////////////////////////////////////////////////
  // remove final column (target column)
  ////////////////////////////////////////////////////////////////////
  FA2RmvCol(  prediction_vector_array , number_of_dimensions - 1); //FA2Printfln( prediction_vector_array, "%2.0f" );
  //FA2AddCol( prediction_vector_array , actual_vector );
  //FA2Printfln( prediction_vector_array, "%2.0f " );
  
  //printf("actual_vector: ");FAPrintL( actual_vector ); 
  //printf("prediction_vector: ");FAPrintL( prediction_vector ); 
  
  
  ////////////////////////////////////////////////////////////////////
  // remove final column //PrintSection( '-', 30);
  ////////////////////////////////////////////////////////////////////
  
  FloatArrayReset( indices_FN ); FloatArrayReset( indices_TN ); FloatArrayReset( indices_FP ); FloatArrayReset( indices_TP ); 
  GetIndices_FN_TN_TP_FP( indices_FN, indices_TN, indices_FP, indices_TP, prediction_vector, actual_vector, V = false ); 
  
  
  FloatArray2Reset( fals_neg ); FloatArray2Reset( true_neg ); FloatArray2Reset( fals_pos ); FloatArray2Reset( true_pos ); 
  GetData_FN_TN_TP_FP( fals_neg, true_neg, true_pos, fals_pos, indices_FN, indices_TN, indices_TP, indices_FP,  prediction_vector_array, V = false ); 
  
  FloatArray2Reset( common ); 
  RmvData_CommonValuesOf_FNTN_AND_TPFP( fals_neg, true_neg, fals_pos, true_pos, common, bufFA2, V = false );
  
  
  FloatArray2Reset( fn_paterns_set ); FloatArray2Reset( tn_paterns_set ); FloatArray2Reset( fp_paterns_set ); FloatArray2Reset( tp_paterns_set ); 
  GetSetsOfPatterns( fn_paterns_set, tn_paterns_set, fp_paterns_set, tp_paterns_set, fals_neg, true_neg, fals_pos, true_pos, number_of_dimensions, bufFA2, V = false ); 
  
  FloatArray2Reset( fn_unique ); FloatArray2Reset( tn_unique ); FloatArray2Reset( fp_unique ); FloatArray2Reset( tp_unique ); 
  GetData_GetPatternsUniqueTo_FN_TN_TP_FP( fn_unique,tn_unique,fp_unique,tp_unique,fn_paterns_set, tn_paterns_set, fp_paterns_set, tp_paterns_set, V = false ); 
  
  FloatArrayReset( prediction_vector );
  bool EXPORT_DATA;
  GetPredictionVectorAugmented( prediction_vector, actual_vector, prediction_vector_array, fn_unique, fp_unique, bufFA2, str, V = false, EXPORT_DATA = false);
  
  FloatArray2Reset( bufFA2 ); 
  FloatArray2CopyToFrom( bufFA2, true_neg, bufFA1 );
  FloatArray2CopyToFrom( bufFA2, true_pos, bufFA1 );
  StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, bufFA2 , "TruePredictions", "%.0f"); 
  StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, fals_neg , "FalseNegatives", "%.0f"); 
  StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, fals_pos , "FalsePositives", "%.0f"); 
 
  
  FloatArray2Reset( bufFA2 ); 
  FloatArray2CopyToFrom( bufFA2, tn_paterns_set, bufFA1 );
  FloatArray2CopyToFrom( bufFA2, tp_paterns_set, bufFA1 );
  StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, bufFA2 , "TruePredictionPatternsAll", "%.0f"); 
  StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, fn_paterns_set , "FalseNegativePatternsAll" , "%.0f"); 
  StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, fp_paterns_set , "FalsePositivePatternsAll" , "%.0f"); 
  

  FloatArray2Reset( bufFA2 ); 
  FloatArray2CopyToFrom( bufFA2, tn_unique, bufFA1 );
  FloatArray2CopyToFrom( bufFA2, tp_unique, bufFA1 );
  StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, bufFA2 , "TruePredictionPatternsUnique", "%.0f"); 
  StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, fn_unique , "FalseNegativePatternsUnique" , "%.0f"); 
  StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, fp_unique , "FalsePositivePatternsUnique" , "%.0f"); 
  
  
  ////////////////////////////////////////////////////////////////////
  // GET SIMILARITY
  ////////////////////////////////////////////////////////////////////
  
  
  float new_training_similarity = FASimilarityRatio( prediction_vector, actual_vector ); 
  
  if(VERBOSE)printf("OLD:%0.2f\n", old_training_similarity );
  if(VERBOSE)printf("NEW:%0.2f\n", new_training_similarity );
  
  if(VERBOSE)PrintSection( '-', 30);
  
  
  
  // instantiate
  selected_data            = data_by_col_test;
  ////////////////////////////////////////////////////////////////////
  // GET SELECTED TARGET VECTORS
  ////////////////////////////////////////////////////////////////////
  f = selected_data->length - 1;
  FloatArrayReset( actual_vector ); 
  FloatArrayCopyToFrom( actual_vector, &selected_data->get[f] ); 
  
  ////////////////////////////////////////////////////////////////////
  // GET PREDICTION VECTOR
  ////////////////////////////////////////////////////////////////////
  FloatArray2Reset( prediction_vector_array ); 
  FloatArrayReset( prediction_vector ); 
  
  
  //FA2PrintL(selected_data); 
  //printf( "%i\n", selected_data->length ); 
  //FA3PrintTables( classify , 4 );
  
  GetPredictionVectorArray( prediction_vector_array, classify, selected_data ); 
  
  GetPredictionVector( prediction_vector, prediction_vector_array, number_of_classes, bufFA1 );
  
  StringAppendChar( str, ',');  StringAddJSONFieldArray2(str, prediction_vector_array , "TestDataPredictionVectors", "%.0f"); 

  
  
  ////////////////////////////////////////////////////////////////////
  // GET SIMILARITY
  ////////////////////////////////////////////////////////////////////
  float old_training_similarity2 = FASimilarityRatio( prediction_vector, actual_vector ); 
  if(VERBOSE)printf("T:%0.2f\n", old_training_similarity2 );
  
  
  ////////////////////////////////////////////////////////////////////
  // free mem
  ////////////////////////////////////////////////////////////////////
  
  
  
  FloatArrayReset( prediction_vector );
  GetPredictionVectorAugmented( prediction_vector, actual_vector, prediction_vector_array, fn_unique, fp_unique, bufFA2, str, FORCE_OUTPUT || VERBOSE, EXPORT_DATA = true  );
  //GetPredictionVectorAugmented2( prediction_vector, actual_vector, prediction_vector_array, fn_unique, fp_unique, tn_unique, tp_unique, bufFA2 );
  
  float testing_similarity = FASimilarityRatio( prediction_vector, actual_vector ); 
  if(VERBOSE)printf("BB:%0.2f\n", old_training_similarity  );
  if(VERBOSE)printf("BA:%0.2f\n", new_training_similarity );
  if(VERBOSE)printf("AB:%0.2f\n", old_training_similarity2  );
  if(VERBOSE)printf("AA:%0.2f\n", testing_similarity );
  
  if(FORCE_OUTPUT || VERBOSE) PrintSection('-', 70 );
  printf("SCORE:");
  printf("(%.2f -> %.2f) -> (%.2f -> %.2f)\n", old_training_similarity, new_training_similarity, old_training_similarity2, testing_similarity );
  
  
  
  StringCloseJSON( str );
  
  StringAppendString2( str, ";}"); 
  StrPrint(str); 
  printf("\n");
  
  return testing_similarity;
}


void StringOpenJSON( String * str ){ StringAppendChar( str , '{' );}
void StringCloseJSON( String * str ){ StringAppendChar( str , '}' );}
void StringAddJSONFieldArray2( String * str, FloatArray2 * data, char * name, char * f ){ 
    StringAppendChar( str , '"' );
    StringAppendString2( str , name );
    StringAppendChar( str , '"' );
    StringAppendString2( str , " : " );
    StringAppendChar( str , '[' );
    
    float val;
    int i, j, L = data->length, L2;
    for(i = 0 ; i < L; i++ ){
        if( i != 0 ) StringAppendString2( str , "," );
        StringAppendChar( str , '[' );
        L2 = data->get[i].length;
        for(j = 0; j < L2; j++ ){
            if( j != 0 ) StringAppendChar( str , ',' );
            val = data->get[i].get[j];
            floatToStringf( val, f , str );
          
        }
        StringAppendChar( str , ']' );
    }
    StringAppendChar( str , ']' );
}



void StringAddJSONFieldArray( String * str, FloatArray * data, char * name, char * f ){ 
  StringAppendChar( str , '"' );
  StringAppendString2( str , name );
  StringAppendChar( str , '"' );
  StringAppendString2( str , " : " );
  StringAppendChar( str , '[' );
  
  float val;
  int i, j, L = data->length, L2;
  for(i = 0 ; i < L; i++ ){
    if( i != 0 ) StringAppendString2( str , "," );
        val = data->get[i];
      floatToStringf( val, f , str );
  }
  StringAppendChar( str , ']' );
}

void PROGRAM( char * loadpath_data ){
  
  
  
  ////////////////////////////////////////////////////////////////////
  // BUFFERS
  ////////////////////////////////////////////////////////////////////
  
  // initialize & instantiate
  String        STRING_BUFFER_1;  StringConstr( &STRING_BUFFER_1, 1000 );
  FloatArray    FA1_BUFFER_1;     FloatArrayConstr( &FA1_BUFFER_1  );
  FloatArray2   FA2_BUFFER_1;     FloatArray2Constr( &FA2_BUFFER_1  );
  
  FloatArray    TARGETS;          FloatArrayConstr( &TARGETS );
  FloatArray3   FA3_BUFFER_1;     FloatArray3Constr( &FA3_BUFFER_1 );
  FloatArray3   FA3_BUFFER_2;     FloatArray3Constr( &FA3_BUFFER_2 );
  FloatArray3   CLASSIFIER;       FloatArray3Constr( &CLASSIFIER );
  FloatArray4   CLASSIFIERS;      FloatArray4Constr( &CLASSIFIERS );
  FloatArray4   FA4_BUFFER_1;     FloatArray4Constr( &FA4_BUFFER_1 );
  FloatArray3   TEST_DATAC;       FloatArray3Constr( &TEST_DATAC );  
  FloatArray3   DATAC;            FloatArray3Constr( &DATAC );
  FloatArray    PREDICTED;        FloatArrayConstr( &PREDICTED );  
  FloatArray    ACTUAL;           FloatArrayConstr( &ACTUAL );  
  
  // pointers
  
  
  
  // set to pointer 
  String      * bufS                = &STRING_BUFFER_1;   
  FloatArray  * bufFA1              = &FA1_BUFFER_1;      
  FloatArray2 * bufFA2              = &FA2_BUFFER_1;       
  FloatArray  * targets             = &TARGETS;
  FloatArray3 * bufFA3A             = &FA3_BUFFER_1;
  FloatArray3 * bufFA3B             = &FA3_BUFFER_2;
  FloatArray4 * bufFA4              = &FA4_BUFFER_1;
  FloatArray3 * classify            = &CLASSIFIER;
  FloatArray4 * classifiers         = &CLASSIFIERS;
  FloatArray  * actual_vector       = &ACTUAL;
  FloatArray  * prediction_vector   = &PREDICTED;
  FloatArray3 * train_by_col_all    = &DATAC;
  FloatArray3 * test_by_col_all     = &TEST_DATAC;
  StringArray * temp_SA_buffer_BCD;
  
  FloatArray2 * train_by_col        = FloatArray3Next( train_by_col_all );
  FloatArray2 * test_by_col         = FloatArray3Next( test_by_col_all );
  
  ////////////////////////////////////////////////////////////////////
  // IMPORT DATA TO FLOAT ARRAY 2 ( COLUMN FORMAT )
  ////////////////////////////////////////////////////////////////////
  
      ////////////////////////////////////////////////////////////////////
      // OPEN MEMORY
      ////////////////////////////////////////////////////////////////////
      
      // initialize & instantiate
      String STRING_1;              StringConstr( &STRING_1, 1000 ); 
      StringArray DATA_CHAR;        StringArrayConstr( &DATA_CHAR );  
      FloatArray DATA;              FloatArrayConstr( &DATA );  
      StringArray CLASS_NAMES;      StringArrayConstr( &CLASS_NAMES );  
      
      // set to pointer 
      String      * super           = &STRING_1;
      StringArray * data_notype     = &DATA_CHAR;
      FloatArray  * float_data      = &DATA;
      StringArray * string_data     = &CLASS_NAMES;
      
      ////////////////////////////////////////////////////////////////////
      // IMPORT CSV/TXT DATA FROM FILE -> PARSE INTO STRING ARRAY
      ////////////////////////////////////////////////////////////////////
      StringParseFromFileDelimeter( super , ' ',',' , loadpath_data );
      StringArrayParseSuperstring( data_notype, super, bufS ); 
      
      ////////////////////////////////////////////////////////////////////
      // HANDLE MISSING VALUES
      ////////////////////////////////////////////////////////////////////
      char * MISSING_VAL_1 = "?";
      StringArrayReplaceWithFloat( data_notype, MISSING_VAL_1, MAX );
      StringArraySeperateFloatsStrings2(  float_data, string_data, data_notype );
      //StringArrayPrintln( data_notype );
      
      
      ////////////////////////////////////////////////////////////////////
      // SPLIT DATA INTO COLUMN ARRAYS
      ////////////////////////////////////////////////////////////////////
      int number_of_dimensions = NUMBER_OF_DIMENSIONS, F = number_of_dimensions - 1;
      FloatArray2ToColumns( train_by_col , float_data, number_of_dimensions , bufFA1 );
      
      ////////////////////////////////////////////////////////////////////
      // REMOVE ALL ROWS WITH INCOMPLETE DATA ( MAX is the value used to signify missing value) 
      ////////////////////////////////////////////////////////////////////
      int MISSING_VALUE = MAX;
      FloatArray * indices = bufFA1;
      FloatArrayReset( indices ); 
      FloatArray2COLGetIndicesOfRowsContaining( indices, train_by_col, MISSING_VALUE ); 
      FloatArray2COLRemoveRows( train_by_col, indices ); 
      
      
      ////////////////////////////////////////////////////////////////////
      // DATASET SPECIFIC FORMATTING
      ////////////////////////////////////////////////////////////////////
      FORMAT_BCD  ( DATASET_BCD_TOGGLE ,  train_by_col, string_data, indices, &number_of_dimensions, bufFA1, temp_SA_buffer_BCD = data_notype );
      FORMAT_HEART( DATASET_HEART_TOGGLE, train_by_col, bufFA2 );
      FORMAT_WDBC ( DATASET_WDBC_TOGGLE, train_by_col, string_data, &number_of_dimensions, temp_SA_buffer_BCD = data_notype, bufFA1 );
    

      ////////////////////////////////////////////////////////////////////
      // FREE MEMORY
      ////////////////////////////////////////////////////////////////////
      StringFree( super ); 
      StringArrayFree( data_notype );
      StringArrayFree( string_data );
      FloatArrayFree( float_data );
  
  ////////////////////////////////////////////////////////////////////
  // FORMAT DATA 
  ////////////////////////////////////////////////////////////////////

      ////////////////////////////////////////////////////////////////////
      // GET AND REMOVE TARGET COLUMN
      ////////////////////////////////////////////////////////////////////
      FA2CGetCol( targets, train_by_col, F );
      FloatArray2RemoveIndex( train_by_col, F , bufFA1 );
      
      ////////////////////////////////////////////////////////////////////
      // NORMALIZE DATA COLUMNS -> ROUND TO n DECIMALS
      ////////////////////////////////////////////////////////////////////
      FloatArray2COLNormalize( train_by_col );
      FloatArray2Round( train_by_col , DECIMALS ); 

      ////////////////////////////////////////////////////////////////////
      // ADD TARGETS BACK IN AS FINAL COLUMN
      ////////////////////////////////////////////////////////////////////
      FloatArray2Add( train_by_col , targets );
  
      ////////////////////////////////////////////////////////////////////
      // RANDOMIZE ROWS ORDER
      ////////////////////////////////////////////////////////////////////
      FloatArray2COLRandomizeRows( train_by_col, bufFA2);
  
  
  ////////////////////////////////////////////////////////////////////
  // BUILD CLASSIFIER
  ////////////////////////////////////////////////////////////////////
  
  ////////////////////////////////////////////////////////////////////
  // OPEN MEMORY
  ////////////////////////////////////////////////////////////////////
  
  FloatArray INDICIES_FN;       FloatArrayConstr( &INDICIES_FN ); 
  FloatArray INDICIES_TP;       FloatArrayConstr( &INDICIES_TP ); 
  FloatArray INDICIES_TN;       FloatArrayConstr( &INDICIES_TN ); 
  FloatArray INDICIES_FP;       FloatArrayConstr( &INDICIES_FP ); 
  FloatArray2 FN;               FloatArray2Constr( &FN);
  FloatArray2 TP;               FloatArray2Constr( &TP);
  FloatArray2 TN;               FloatArray2Constr( &TN);
  FloatArray2 FP;               FloatArray2Constr( &FP);
  FloatArray2 FN_PATTERNS;      FloatArray2Constr( &FN_PATTERNS);
  FloatArray2 TP_PATTERNS;      FloatArray2Constr( &TP_PATTERNS);
  FloatArray2 TN_PATTERNS;      FloatArray2Constr( &TN_PATTERNS);
  FloatArray2 FP_PATTERNS;      FloatArray2Constr( &FP_PATTERNS);
  FloatArray2 FN_SET;           FloatArray2Constr( &FN_SET);
  FloatArray2 TP_SET;           FloatArray2Constr( &TP_SET);
  FloatArray2 TN_SET;           FloatArray2Constr( &TN_SET);
  FloatArray2 FP_SET;           FloatArray2Constr( &FP_SET);
  FloatArray2 FN_UNIQUE;        FloatArray2Constr( &FN_UNIQUE);
  FloatArray2 TP_UNIQUE;        FloatArray2Constr( &TP_UNIQUE);
  FloatArray2 TN_UNIQUE;        FloatArray2Constr( &TN_UNIQUE);
  FloatArray2 FP_UNIQUE;        FloatArray2Constr( &FP_UNIQUE);
  FloatArray2 COMMON;           FloatArray2Constr( &COMMON);
  FloatArray2 PREDICTED_ARRAY;  FloatArray2Constr( &PREDICTED_ARRAY ); 
  
  FloatArray2 * prediction_vector_array   = &PREDICTED_ARRAY;
  FloatArray * indices_FN       =    &INDICIES_FN;
  FloatArray * indices_TP       =    &INDICIES_TP;
  FloatArray * indices_TN       =    &INDICIES_TN;
  FloatArray * indices_FP       =    &INDICIES_FP;
  FloatArray2 * fals_neg        =    &FN;
  FloatArray2 * true_pos        =    &TP;
  FloatArray2 * true_neg        =    &TN;
  FloatArray2 * fals_pos        =    &FP;
  FloatArray2 * fn_paterns      =    &FN_PATTERNS;
  FloatArray2 * tp_paterns      =    &TP_PATTERNS;
  FloatArray2 * tn_paterns      =    &TN_PATTERNS;
  FloatArray2 * fp_paterns      =    &FP_PATTERNS;
  FloatArray2 * fn_paterns_set  =    &FN_SET;
  FloatArray2 * tp_paterns_set  =    &TP_SET;
  FloatArray2 * tn_paterns_set  =    &TN_SET;
  FloatArray2 * fp_paterns_set  =    &FP_SET;
  FloatArray2 * common          =    &COMMON;
  
  FloatArray2 * fn_unique       =    &FN_UNIQUE;
  FloatArray2 * tn_unique       =    &TN_UNIQUE;
  FloatArray2 * fp_unique       =    &FP_UNIQUE;
  FloatArray2 * tp_unique       =    &TP_UNIQUE;
  
  int count, index, L, L2;
  FloatArray *fa,*fb;
  bool eq;
  bool V;
  
  ////////////////////////////////////////////////////////////////////
  // Build Classifier
  ////////////////////////////////////////////////////////////////////
  
      int number_of_classes, K;
      
      BuildClassifier2( classifiers, &number_of_classes, train_by_col_all, test_by_col_all, number_of_dimensions, K = 10, bufFA4 );
      ////////////////////////////////////////////////////////////////////
      // SELECT DATA
      ////////////////////////////////////////////////////////////////////
      K = -1; // REMOVE 
      float score, total = 0;
      if( K == -1) K = 1;
      for(int i = 0 ; i < K; i++ ){
        score = UseClassifier(  i, 
                        classifiers, train_by_col_all, test_by_col_all, prediction_vector_array, 
                        fals_neg, true_neg, true_pos, fals_pos, common, 
                        fn_paterns_set, tn_paterns_set,fp_paterns_set,tp_paterns_set,
                        fn_unique, tn_unique, fp_unique, tp_unique, bufFA2,
                        indices_FN, indices_TN, indices_FP, indices_TP, bufFA1,
                        actual_vector, prediction_vector, number_of_classes, number_of_dimensions, V  = false );
        total += score;
      }
      PrintSection('-', 50 );
      printf("TOTAL: %.8f\n", total / K );
        
        
     
      
       // void StringOpenJSON( String * str ){ StringAppendChar( str , '{' );}
      //  void StringCloseJSON( String * str ){ StringAppendChar( str , '}' );}
      //  void StringAddJSONFieldArray( String * str, FloatArray2 * data, char * name, char * f ){ 
      
      
    // exit(0);SvgClose( svg ); SvgExport2( svg, filename->get ); StringFree( svg );
}


void histogramMatchBins( FloatArray * val1,FloatArray * cnt1,FloatArray * val2,FloatArray * cnt2){
  
  FloatArray TEMP; FloatArray * temp = &TEMP; FloatArrayConstr( temp ); 
  FloatArray BINS; FloatArray * bins = &BINS; FloatArrayConstr( bins ); 
  
  FloatArrayCopyFromTo( val1, temp );
  FloatArrayCopyFromTo( val2, temp );
  
  FloatArrayGetUnique( bins, temp );
  FloatArrayReset( temp );
  
  int i , j;
  float v1, v2;
  FloatArray * value  = val1;
  FloatArray * count  = cnt1;
  for( i = 0 ; i < bins->length; i++ ){
    v1 = bins->get[i];
    for( j = 0 ; j < value->length; j++ ){
      v2 = value->get[j];  
      if( v1 == v2 ){
        FloatArrayAdd( temp , count->get[j] ); 
        break;
      }
      if( j == value->length-1 ){
        FloatArrayAdd( temp , 0.0f ); 
      }
    }
  }
  
  
  
  
  FloatArrayReset( val1 ); 
  FloatArrayCopyFromTo( bins, val1);
  
  FloatArrayReset( cnt1 ); 
  FloatArrayCopyFromTo( temp, cnt1 );
  
  FloatArrayReset( temp ); 
  
  value  = val2;
  count  = cnt2;
  for( i = 0 ; i < bins->length; i++ ){
    v1 = bins->get[i];
    for( j = 0 ; j < value->length; j++ ){
      v2 = value->get[j];  
      if( v1 == v2 ){
        FloatArrayAdd( temp , count->get[j] ); 
        break;
      }
      if( j == value->length-1 ){
        FloatArrayAdd( temp , 0.0f ); 
      }
    }
  }
  
  FloatArrayReset( val2 ); 
  FloatArrayCopyFromTo( bins, val2);
  
  FloatArrayReset( cnt2 ); 
  FloatArrayCopyFromTo( temp, cnt2 );
  
  
  FACPrintfBr( val1 , "%.2f\t", 10);
  FACPrintfBr( cnt1 , "%.2f\t", 10);
  FACPrintfBr( val2 , "%.2f\t", 10);
  FACPrintfBr( cnt2 , "%.2f\t", 10);
  
  FloatArrayFree( bins ); 
  FloatArrayFree( temp ); 
}

void svgHisto( LineArray * lines, FloatArray * hist_vals,FloatArray * hist_cnts,  float scaleX, float scaleY ){
  int VALUES = 0, COUNTS = 1;
  int BINS = hist_vals->length;
  FANormalize( hist_cnts);
  //FloatArrayPrint( &hist->get[ COUNTS ] );
  //float scaleX = 0.95f;
  //float scaleY = 0.95f;
  float marginX =  100.0f - (100.0f * scaleX);
  float marginY = 100.0f - (100.0f * scaleY);;//(100.0f * scaleY);
  float spaceX = 100.0f -  ( marginX * 2 );
  float spaceY = 100.0f -  ( marginY * 2 );
  float sizeX = spaceX / BINS;
  float sizeY = 100 - marginY - marginY;
  int i;
  float x, y;
  float epsilonX = -0.15f;
  for( i = 0 ; i < BINS; i++ ){
    x = (sizeX * i) + marginX;
    y = 100 - marginY;
    sizeY = (100 - marginY - marginY) * hist_cnts->get[i];
    LineArrayAdd( lines, x + epsilonX,y,x + (sizeX) - epsilonX, y,"nn"); // bottom
    LineArrayAdd( lines, x,y,x, y - sizeY ,"nn");
    LineArrayAdd( lines, x +epsilonX,y - sizeY,x + (sizeX) - epsilonX, y - sizeY,"nn");
    LineArrayAdd( lines, x + (sizeX),y,x + (sizeX), y - sizeY ,"nn");
    
  }
}


void SVGHistogram( String * svg, FloatArray * histo_vals, FloatArray * histo_cnts ){
  
  
  String BUFFERS; String * bufferS = &BUFFERS; StringConstr( bufferS , 1000 ); 
  
  
  
  FloatArray BUFFERFA; FloatArray * bufferFA1 = &BUFFERFA; FloatArrayConstr( bufferFA1 ); 
  FloatArray PARAMS; FloatArray * params = &PARAMS; FloatArrayConstr( params ); 
  FloatArray2 COLORS; FloatArray2 * colors = &COLORS; FloatArray2Constr( colors ); 
  
  LineArray LINES; LineArray * lines = &LINES; LineArrayConstr( lines ); 
  FloatArray2 DATA; FloatArray2 * data_by_column = &DATA; FloatArray2Constr( data_by_column ); 
  
  PointArray POINTS; PointArray * points = &POINTS; PointArrayConstr( points , data_by_column->length ); 
  
  
  
  int number_of_boxes = histo_vals ->length;
  
  float scaleX = 0.85f;
  float scaleY = 0.80f;
  
  svgHisto( lines, histo_vals, histo_cnts, scaleX, scaleY ); 
  
  //LineArrayShiftY( lines, -offY); 
  //LineArrayShiftX( lines, offX); 
  SvgAddLines( svg, lines, "black", 0.35f , 1.0f );
  
  
  
  //FA2GetColors( colors );
  //SvgClassifier( svg, params, colors, classify );
  
  //int row = 20;
  //PointArrayGetFA2CRowToY( points  , data_by_column , row );
  //PointArraySetXAll( points, 0.5f ); 
  //LineArrayReset( lines );  
  //LineArrayParsePointArray( lines, points, points->length );
  
  //if(VERBOSE)PointArrayPrint( points );
  //if(VERBOSE)LineArrayPrint( lines  );
  
  //int id;
  //SvgAddLineFromToIndex( svg, 0.2,0.8, 0, 1,  sizeX,  sizeY,  marginX,  marginY,  4.0 , id= 0);
  //SvgAddLineArray( svg, lines, sizeX,  sizeY,  marginX,  marginY,  1.0  ); 
  
  //GetClassPredictions( NULL , classify, points ); 
  
  
  
  
  
  
  StringFree( bufferS );
  
  
  FloatArrayFree( bufferFA1 ); 
  FloatArrayFree( params ); 
  FloatArray2Free( colors ); 
  FloatArray2Free( data_by_column ); 
  LineArrayFree( lines ); 
  PointArrayFree( points ); 
}
void FA2Histogram( FloatArray2 * histo, FloatArray2 * data, int dimension_enum, int class_enum ){
  
  int class_dimension = data->length - 1; // last col by convention
  FloatArray IDX; FloatArray * idx = &IDX; FloatArrayConstr( idx );
  FloatArray COL; FloatArray * col = &COL; FloatArrayConstr( col );
  
  FloatArray * set = FloatArray2Next( histo ); 
  FloatArray * cnt = FloatArray2Next( histo ); 
  FloatArray * cls = &data->get[ class_dimension ];
  FloatArray * dat = &data->get[ dimension_enum ];
  //FACPrintfBr( dat , "%.2f\t", 10);
  
  FAIndicesOf( idx , cls, class_enum ); 
  //FACPrintfBr( idx , "%.2f\t", 10);
  
  FAGetIndices( col, dat, idx );
  //FACPrintfBr( col , "%.2f\t", 10);
  
  FloatArrayGetUnique( set, col );
  //FACPrintfBr( set , "%.2f\t", 10);
  
  FACountValues( cnt, col, set );
  //FACPrintfBr( cnt , "%.2f\t", 10);
  
  FloatArrayFree(idx);
  FloatArrayFree(col);
}


void encodeSVG( FloatArray3 * k_fold_slices , FloatArray3 * classify, int row, char * filename ){
  bool VERBOSE = false;
  
  String BUFFERS; String * bufferS = &BUFFERS; StringConstr( bufferS , 1000 ); 
  String SVG; String * svg = &SVG; StringConstr( svg , 1000 ); 
  String FILEPATH; String * filepath = &FILEPATH; StringConstr( filepath , 1000 ); 
  
  FloatArray BUFFERFA; FloatArray * bufferFA1 = &BUFFERFA; FloatArrayConstr( bufferFA1 ); 
  FloatArray PARAMS; FloatArray * params = &PARAMS; FloatArrayConstr( params ); 
  FloatArray2 COLORS; FloatArray2 * colors = &COLORS; FloatArray2Constr( colors ); 
  
  LineArray LINES; LineArray * lines = &LINES; LineArrayConstr( lines ); 
  FloatArray2 DATA; FloatArray2 * data_by_column = &DATA; FloatArray2Constr( data_by_column ); 
  
  
  
  
  // grab all but last k-fold splits
  int i, j, k;
  for(i = 1 ; i < k_fold_slices->get[0].length; i++ ) FloatArray2AddEmpty( data_by_column );
  
  for( i = 0 ; i < k_fold_slices->length -1 ; i++ ){
    
    for( j = 0 ; j < k_fold_slices->get[i].length  - 1; j++ ){
      
      for( k = 0 ; k < k_fold_slices->get[i].get[j].length ; k++ ){
        FloatArrayAdd( &data_by_column->get[j], k_fold_slices->get[i].get[j].get[k] ); 
      }
      
    }
    
  }
  
  PointArray POINTS; PointArray * points = &POINTS; PointArrayConstr( points , data_by_column->length ); 
  
  classify -> length --; // -1 to remove the target dimension
  
  SvgOpen( &SVG ); 
  
  int number_of_boxes = classify -> length; 
  
  float scaleX = 0.85f;
  float scaleY = 0.80f;
  float marginX =  100.0f - (100.0f * scaleX);
  float marginY = 100.0f - (100.0f * scaleY);;//(100.0f * scaleY);
  float spaceX = 100.0f -  ( marginX * 2 );
  float spaceY = 100.0f -  ( marginY * 2 );
  float sizeX = spaceX / number_of_boxes;
  float sizeY = 100 - marginY - marginY;
  float offX = 0.0f, offY = 0.0f;
  SvgDisplayParameters( params, sizeX, sizeY, marginX, marginY ); 
  
  
  LineArrayColocatedPairsPreset( lines, number_of_boxes, scaleX, scaleY , bufferFA1 ); 
  LineArrayShiftY( lines, -offY); 
  LineArrayShiftX( lines, offX); 
  SvgAddLines( svg, lines, "black", 0.35f , 1.0f );
  
  FA2GetColors( colors );
  SvgClassifier( svg, params, colors, classify );
  
  //int row = 20;
  PointArrayGetFA2CRowToY( points  , data_by_column , row );
  PointArraySetXAll( points, 0.5f ); 
  LineArrayReset( lines );  
  LineArrayParsePointArray( lines, points, points->length );
  
  if(VERBOSE)PointArrayPrint( points );
  if(VERBOSE)LineArrayPrint( lines  );
  
  int id;
  //SvgAddLineFromToIndex( svg, 0.2,0.8, 0, 1,  sizeX,  sizeY,  marginX,  marginY,  4.0 , id= 0);
  SvgAddLineArray( svg, lines, sizeX,  sizeY,  marginX,  marginY,  1.0  ); 
  
  GetClassPredictions( NULL , classify, points ); 
  
  
  SvgClose( &SVG ); 
  
  StringAppendString2( filepath , "/Users/macbook/desktop/");
  StringAppendString2( filepath , filename );
  //exportStringSVG_FILEPATH( &SVG, bufferS, filepath->get ); 
  
  
  StringFree( bufferS );
  StringFree( svg );
  StringFree( filepath );
  FloatArrayFree( bufferFA1 ); 
  FloatArrayFree( params ); 
  FloatArray2Free( colors ); 
  FloatArray2Free( data_by_column ); 
  LineArrayFree( lines ); 
  PointArrayFree( points ); 
  
  classify -> length ++; 
}




void ColorFA2AddRed( FloatArray2 * colors ){
  FloatArray * new_color = FloatArray2Next( colors );    
  FloatArrayAdd( new_color , 255.0f ); 
  FloatArrayAdd( new_color , 0.0f ); 
  FloatArrayAdd( new_color , 0.0f ); 
}

void ColorFA2AddBlue( FloatArray2 * colors ){
  FloatArray * new_color = FloatArray2Next( colors );    
  FloatArrayAdd( new_color , 0.0f ); 
  FloatArrayAdd( new_color , 0.0f ); 
  FloatArrayAdd( new_color , 255.0f ); 
}

void FA2GetColors( FloatArray2 * colors ){
  ColorFA2AddBlue( colors ); 
  ColorFA2AddRed( colors );
  
}

float ClassifierTableIntervalA( FloatArray2 * tableX , int index ){
  return tableX->get[index].get[0];
}
float ClassifierTableIntervalB( FloatArray2 * tableX , int index ){
  return tableX->get[index].get[1];
}
float ClassifierTableClassCount( FloatArray2 * tableX , int index, int class_enum ){
  int class_enum_after_two_intervals_indices = class_enum + 2;
  return tableX->get[index].get[ class_enum_after_two_intervals_indices ];
}



void SvgDisplayParameters( FloatArray * params, float sizeX, float sizeY, float marginX, float marginY ){
  FloatArrayAdd( params, sizeX );
  FloatArrayAdd( params, sizeY );
  FloatArrayAdd( params, marginX );
  FloatArrayAdd( params, marginY );
}
void SvgClassifier( String * svg, FloatArray * params, FloatArray2 * colors , FloatArray3 * classifier ){
  bool VERBOSE = false;
  float sizeX = params -> get[0];
  float sizeY = params -> get[1];
  float marginX = params -> get[2];
  float marginY = params -> get[3];
  
  // ClassifierTableClassCount 
  
  float x1,y1,x2,y2, opacity, val;
  int R,G,B;
  int color = 1;
  int initial_col = 2;
  int i, j , k;
  int index;
  int L1 = classifier ->length, L2;
  int classes = classifier ->get[0].get[0].length - initial_col, cls_idx;
  int col_max;
  for( i = 0 ; i < L1; i++ ){
    index = i;
    L2 = classifier ->get[i].length;
    for( j = 0 ; j < L2; j++ ){
      y1 = ClassifierTableIntervalA( &classifier ->get[i], j );
      y2 = ClassifierTableIntervalB( &classifier ->get[i], j );
      if(y1 == y2 ) y2 += 0.01;
      col_max = FATotalFromTo( &classifier ->get[i].get[j] , initial_col, - 1); 
      color = FA2CMaxIndexFromTo( &classifier ->get[i] , j, initial_col, -1) - initial_col;
      R = colors->get[ color ].get[0];
      G = colors->get[ color ].get[1];
      B = colors->get[ color ].get[2];
      k = color;
      
      cls_idx = k + initial_col;
      val =  (classifier ->get[i].get[j].get[ cls_idx ]);
      if(val == 0.0f ) continue;
      opacity = (val / col_max) * .85;
      if(VERBOSE)printf("color(%i)\t val(%.2f)\t ttl(%i)\t opacity(%.3f)\n", color, val, col_max, opacity ); 
      SvgAddRectOpacityIndex( svg, y1,y2, sizeX, sizeY, marginX, marginY, index , R, G, B , opacity );  
    }
  }
  
  //y1 = 0.2f;
  //y2 = 0.3f;
  
  
  
}


void LineArrayColocatedPairsPreset( LineArray * lines, int dimensions, float scaleX, float scaleY,  FloatArray * bufferFA ){
  FloatArrayReset( bufferFA ); 
  int DIMENSIONS = dimensions;
  //float scaleX = 0.95f;
  //float scaleY = 0.95f;
  float marginX =  100.0f - (100.0f * scaleX);
  float marginY = 100.0f - (100.0f * scaleY);;//(100.0f * scaleY);
  float spaceX = 100.0f -  ( marginX * 2 );
  float spaceY = 100.0f -  ( marginY * 2 );
  float sizeX = spaceX / DIMENSIONS;
  float sizeY = 100 - marginY - marginY;
  int i;
  float x, y;
  float epsilonX = -0.15f;
  for( i = 0 ; i < dimensions; i++ ){
    x = (sizeX * i) + marginX;
    y = 100 - marginY;
    LineArrayAdd( lines, x + epsilonX,y,x + (sizeX) - epsilonX, y,"nn"); // bottom
    LineArrayAdd( lines, x,y,x, y - sizeY ,"nn");
    LineArrayAdd( lines, x +epsilonX,y - sizeY,x + (sizeX) - epsilonX, y - sizeY,"nn");
    LineArrayAdd( lines, x + (sizeX),y,x + (sizeX), y - sizeY ,"nn");
  }
}
void FloatArray2InsertColEmpty(FloatArray2 * data, int col_pos){
  int i , j;
  int L1 = data->length;
  for( i = 0 ; i < L1; i++ ){
    FloatArrayAdd( &data->get[i], 0.0f );
  }
  int L2 = data->get[0].length;
  if( col_pos < L2 ){ 
    for( i = 0 ; i < L1; i++ ){
      for( j = L2 - 1; j > col_pos; j-- ){
        data->get[i].get[j] = data->get[i].get[j-1];
      }
    }
  }
  
}


void FloatArrayOverwriteCol( FloatArray2 * floats , FloatArray * flt, int col ){
  int i , j;
  int L1 = floats ->length;
  int index = 0;
  for( i = 0 ; i < L1; i++ ){
    floats->get[i].get[col] = flt->get[i];
  }
}




void Sort2AscColAndLast( FloatArray2 * segments, FloatArray2 * values_in_columns, int column, FloatArray3 * buffer3, FloatArray2 * buffer2, FloatArray * buffer1){
  
  
  FloatArrayReset(buffer1); 
  FloatArray2Reset(buffer2); 
  FloatArray3Reset(buffer3); 
  
  bool VERBOSE = false;
  int dimension_containing_class_enums = values_in_columns ->length - 1;
  
  FloatArray3InstantiateD1( buffer3, 3, buffer2, buffer1);
  FloatArray2 * buffer2A = &buffer3->get[0];
  FloatArray2 * buffer2B = &buffer3->get[2];
  
  
  FloatArray2InitializeD1( buffer2B, 2, buffer1);
  FloatArray * buffer1A = &buffer2B->get[0];
  FloatArray * buffer1B = &buffer2B->get[1];
  
  FloatArrayReset( buffer1A ); 
  FloatArray2Reset( buffer2A ); 
  FloatArray2InitializeD1( buffer2A, 4, buffer1A ); 
  FloatArray * unsorted  = &buffer2A->get[ 0 ];
  FloatArray * sorted = &buffer2A->get[ 1 ];
  FloatArray * map = &buffer2A->get[ 2 ];
  FloatArray * indices = &buffer2A->get[ 3 ];
  
  
  // add data
  FloatArrayCopyFromTo( &values_in_columns->get[column], unsorted );
  FloatArrayCopyFromTo( &values_in_columns->get[column], sorted );
  FloatArraySortAsc( sorted );
  FloatArrayReset( buffer1A );
  FloatArraySortMap2( map, unsorted, sorted , buffer1A );
  
  
  // get segment starts
  FloatArrayReset( indices );
  FloatArrayGetValueSet( indices, sorted ); //FloatArrayPrint( indices );
  //FloatArrayPrint( sorted );
  //FloatArrayPrintCompare( indices , sorted );
  
  
  int cls, index,init,finl;
  float val_this;
  int i, j;
  for( i = 0 ; i < indices->length; i++ ){
    init = i < indices->length - 1 ? indices->get[i] : indices->get[i];
    finl = i < indices->length - 1 ? indices->get[i + 1] - 1: unsorted -> length - 1;
    FloatArrayReset( buffer1A );
    if(VERBOSE)printf("scanning block %i -> %i\n", init, finl); 
    for(j = init; j < finl + 1; j++ ){
      //printf("%i ", j); 
      index = map->get[j];
      val_this = sorted->get[j];
      cls = (int)values_in_columns->get[ dimension_containing_class_enums ].get[ index ];
      FloatArrayAdd( buffer1A , cls );
      if(VERBOSE)printf("[%i] VAL:%.2f\tCLS:%i\n", j ,val_this , cls ); 
    }
    
    FloatArraySortAsc( buffer1A );
    if(VERBOSE)printf("SORTING SECONDARY COLUMN\n"); 
    
    for(j = init; j < finl + 1; j++ ){
      index = map->get[j];
      
      val_this =  unsorted->get[index];
      cls = buffer1A->get[ j - init];
      
      if(VERBOSE)printf("[%i] %.2f\t<-\t%.2f\n", j ,values_in_columns->get[ dimension_containing_class_enums ].get[ index ] , buffer1A->get[ j - init] ); 
      values_in_columns->get[ dimension_containing_class_enums ].get[ index ] = cls;//buffer->get[ j - init];
      
      FloatArrayReset( buffer1B );
      FloatArrayAdd( buffer1B , val_this );
      FloatArrayAdd( buffer1B , cls ); 
      FloatArray2Add( segments, buffer1B ); 
    }
  }
}


void StringAddSubtitleInt( char * title, int num, String * out ){
  char buf[10];
  sprintf( buf, "%i", num ); 
  StringAppendString2( out , title );
  StringAppendString2( out , buf );
  StringAppendString2( out , "\n");
}
void StringAddTitle( char * title, String * out ){
  StringAppendString2( out , title );
  StringAppendString2( out , "\n");
  StringAppendString2( out , "-------------------------------------------------------------------\n");
}

void StringAddLine( int lines,  String * out ){
  int i;
  for(i = 0 ; i < lines; i++ ){
    StringAppendString2( out , "\n");  
  }
}

void OutFloatArray2COLColEx( char * title, FloatArray2 * cols, String * out  ){
  
  StringAddTitle(  title , out ); 
  int i, j , k;
  for(i = 0 ; i < cols->length; i++ ){
    StringAddSubtitleInt("\nCOLUMN ", i,  out );
    FloatArrayToStringf( &cols->get[i], "%.2f ", out );  
    StringAddLine(  1 , out );
  }
  StringAddLine(  4 , out );
}



int getClassCount( FloatArray2 * data, int class_column , FloatArray * bufferFA ){
  int i, j;
  bool nonexist;
  bool VERBOSE = false;
  //printf("dimension print: "); 
  FloatArrayReset( bufferFA ); 
  int L = data->get[0].length;
  float val;
  for( i = 0; i < L; i++ ){
    val = data->get[ class_column ].get[ i ];
    if(VERBOSE)printf("%f\n", val);
    if( bufferFA->length == 0 ){ FloatArrayAdd( bufferFA, val ); continue; }
    nonexist = ! FloatArrayContains( bufferFA ,  val); 
    if( nonexist ) FloatArrayAdd( bufferFA, val );
  }
  return bufferFA->length;
}


void FloatArray2COLSplitToRatio( float test_ratio, FloatArray2 * data_in_col_1, FloatArray2 * data_in_col_2, FloatArray3 * buf3, FloatArray * buf1 ){
  int index_of_class_column, number_of_classes;
  FloatArrayReset( buf1 ); 
  FloatArray3Reset( buf3 ); 
  index_of_class_column = data_in_col_1 -> length - 1;
  number_of_classes = getClassCount( data_in_col_1 , index_of_class_column , buf1 );
  FloatArray2Split2(data_in_col_2, data_in_col_1, test_ratio, number_of_classes, buf3 );
}


void BuildClassifer( FloatArray3 * tables, FloatArray2 * training_data, int number_of_dimensions, int number_of_classes, float join_ratio, FloatArray3 * memoryFA3, FloatArray3 * buf3B, String * out ){
  
  
  bool is_class_identifer_column;
  int current_dimension, actual_column, index_of_class_column;
  int total = 0, correct = 0;
  
  
  index_of_class_column = training_data -> length;
  FloatArray2 * training_data_copy  = FloatArray3Next( memoryFA3 ); 
  FloatArray2 * sort2d_val_cls      = FloatArray3Next( memoryFA3 ); 
  FloatArray2 * buffer2A            = FloatArray3Next( memoryFA3 ); 
  FloatArray2 * buffer2B            = FloatArray3Next( memoryFA3 ); 
  FloatArray  * buffer              = FloatArray2Next( buffer2B ); 
  FloatArray2 * consolidated_cls    = FloatArray3Next( memoryFA3 ); 
  FloatArray2 * consolidated_vals   = FloatArray3Next( memoryFA3 );
  FloatArray2 * intervals           = FloatArray3Next( memoryFA3 );
  
  
  
  
  int i , j , k;  
  for( i = 0 ; i < number_of_dimensions; i++ ){ // 2; i++){ number_of_dimensions
    current_dimension = i;
    actual_column = current_dimension > index_of_class_column ? current_dimension + 1 : current_dimension;
    is_class_identifer_column = current_dimension == index_of_class_column;
    if(is_class_identifer_column) continue;
    
    FloatArrayReset( buffer ); 
    FloatArray2Reset(training_data_copy); 
    FloatArray2CopyToFrom( training_data_copy, training_data , buffer);
    
    ////////////////////////////////////////////////////////////////////
    // show which table is being built
    //////////////////////////////////////////////////////////////////// 
    
    FloatArrayReset( buffer );
    FloatArray2Reset( sort2d_val_cls ); 
    FloatArray2Reset( buffer2A ); 
    FloatArray3Reset( buf3B ); 
    //StringAddSubtitleInt( "TRAINING VALUES. DIMENSION: ", i, out );
    
    
    Sort2AscColAndLast( sort2d_val_cls, training_data_copy, current_dimension, buf3B, buffer2A, buffer ); 
    //OutFloatArray2COLCol("NEW  DATA...", sort2d_val_cls, out );
    
    
    
    // here
    
    ////////////////////////////////////////////////////////////////////
    // conslidate values 
    //////////////////////////////////////////////////////////////////// 
    FloatArray2Reset( consolidated_cls );
    ConsolidateByClass( consolidated_cls, sort2d_val_cls);
    //StringAddSubtitleInt( "CONSOLIDATED BY CLASS. DIMENSION: ", i, out );
    //OutFloatArray2COLCol( "", consolidated_cls, out );
    //    printf("-----------cosolidated classes (%i)---------------\n", i);
    //    FloatArray2PrintByRow( consolidated_cls, consolidated_cls -> length );
    
    
    ////////////////////////////////////////////////////////////////////
    // conslidate by value, class 
    //////////////////////////////////////////////////////////////////// 
    
    //    printf("-----------cosolidated values (%i)---------------\n", i);
    FloatArray2Reset( consolidated_vals );
    ConsolidateByValue( consolidated_vals, consolidated_cls, number_of_classes, buffer );
    //StringAddSubtitleInt( "CONSOLIDATED BY VALUE. DIMENSION: ", i, out );
    //OutFloatArray2COLCol( "", consolidated_vals, out );
    //   FloatArray2PrintByRow( consolidated_vals, consolidated_vals -> length );
    
    ////////////////////////////////////////////////////////////////////
    // conslidate by value, class 
    //////////////////////////////////////////////////////////////////// 
    
    //   printf("-----------joined continguous values (%i)---------------\n", i);
    FloatArray3Reset( buf3B ); 
    FloatArray2Reset( intervals );
    JoinClassRatiosGreaterThan( intervals, consolidated_vals , join_ratio , buf3B );
    StringAddSubtitleInt( "JOINED. DIMENSION: ", i, out );
    OutFloatArray2COLCol( "", intervals, out );
    //   FloatArray2PrintByRow( consolidated_vals, consolidated_vals -> length );
    
    
    
    FloatArray3Add( tables , intervals );
    
  }
  
  
}
int GetClassificationIndex( FloatArray2 * classification_dimension , float val ){
  int i , j , k;
  int L2, L3;
  float val1, val2;
  bool within;
  FloatArray2 * dimension = classification_dimension;
  L2 = dimension->length;
  int COL_INTERVAL_A = 0, COL_INTERVAL_B = 1;
  for( i = 0 ; i < L2; i++ ){
    val1 = dimension -> get[i].get[0];
    val2 = dimension -> get[i].get[1];
    within = val1 <= val && val <= val2;  
    if( within ) return i;
  }
  return -1;
}

int GetTotalClassMembers( FloatArray3 * classifications , int col, float val ){
  bool VERBOSE = false; 
  int i , j , k;
  int L2, L3;
  int from_col = 2;
  int index, index2, max, predicted = -1, actual;
  float val1, val2;
  FloatArray2 * dimension = &classifications ->get[ col ];
  index = GetClassificationIndex( dimension , val );
  if(index == -1) return -1;
  FloatArray * row = &dimension->get[index];
  max = FATotalFromTo(  row , 2, -1 );
  
  //index2 = FloatArrayGetIndexFirstOccurance( row, max );
  
  //predicted = index2 - from_col;
  
  //predicted = predicted < 0 ? -1 : predicted;
  //if(VERBOSE)printf("DIMENSION: %i\t VALUE:%.2f\t PREDICTED:%i\n", col, val, predicted ); 
  return max;
  
}

float GetPredictedClassIntervalSize( FloatArray3 * classifications , int col, float val ){
  bool VERBOSE = false; 
  int i , j , k;
  int L2, L3;
  int from_col = 2;
  int index, index2, max, predicted = -1, actual;
  float val1, val2;
  FloatArray2 * dimension = &classifications ->get[ col ];
  index = GetClassificationIndex( dimension , val );
  if(index == -1) return -1;
  FloatArray * row = &dimension->get[index];
  float interval_size = row->get[1] - row->get[0];
  
  return interval_size;
}

int GetPredictedClass( FloatArray3 * classifications , int col, float val ){
  bool VERBOSE = false; 
  int i , j , k;
  int L2, L3;
  int from_col = 2;
  int index, index2, max, predicted = -1, actual;
  float val1, val2;
  FloatArray2 * dimension = &classifications ->get[ col ];
  index = GetClassificationIndex( dimension , val );
  if(index == -1) return -1;
  FloatArray * row = &dimension->get[index];
  max = FloatArrayGetMaxFrom(row, from_col );
  
  index2 = FloatArrayGetIndexFirstOccurance( row, max );
  
  predicted = index2 - from_col;
  
  predicted = predicted < 0 ? -1 : predicted;
  //if(VERBOSE)printf("DIMENSION: %i\t VALUE:%.2f\t PREDICTED:%i\n", col, val, predicted ); 
  return predicted;
}



int GetActualClass( FloatArray2 * values , int row ){
  int COL_CLASS = values ->length - 1;
  int L1 = values ->get[0].length;
  return values ->get[ COL_CLASS ].get[ row ];
}

int GetActualClassMembers( FloatArray3 * classifications , int col, float val, int cls ){
  bool VERBOSE = false; 
  int i , j , k;
  int L2, L3;
  int from_col = 2;
  int index, members = 0, adjusted_index;
  float val1, val2;
  FloatArray2 * dimension = &classifications ->get[ col ];
  
  index = GetClassificationIndex( dimension , val );
  if(index == -1) members = 0;
  else{
    FloatArray * row = &dimension->get[index];
    adjusted_index = cls + from_col;
    members = row ->get[ adjusted_index ];
  }
  
  if(VERBOSE)printf("DIMENSION: %i\t VALUE:%.2f\t CLS:%i \t MEMBERS:%i\n", col, val, cls, members ); 
  return members;
}


void GetClassPredictions( FloatArray * predictions, FloatArray3 * classifier, PointArray * data  ){
  bool VERBOSE = true;
  
  
  
  
  
  int L1 = data ->length;
  int i;
  int col, predicted_class, members;
  float val;
  if(VERBOSE)printf("Predicted: "); 
  for( i = 0 ; i < L1; i++ ){
    col = i;
    val = data ->y[ i ];
    predicted_class = GetPredictedClass( classifier , col, val );  
    //FloatArrayAdd( predictions, predicted_class ); 
    if(VERBOSE)printf("(%i) ", predicted_class); 
  }
  if(VERBOSE) printf("\n"); 
  
  
  
  
  
}

void RecordClassifierFails( FloatArray3 * classifier, FloatArray2 * output_data, int col, float val, int predicted, int actual, int members  ){
  
  FloatArray2 * dimension; FloatArray * row_vals;
  
  
  FloatArray2AddNew( output_data, col );
  FloatArray2AddToLast( output_data, val );
  
  
  
  dimension = &classifier ->get[ col ];
  int index = GetClassificationIndex( dimension , val );
  if(index == -1){ 
    FloatArray2AddToLast( output_data, -1 );
    FloatArray2AddToLast( output_data, -1 );
  } else {
    
    row_vals = &dimension->get[index];
    FloatArray2AddToLast( output_data, row_vals->get[0] );
    FloatArray2AddToLast( output_data, row_vals->get[1] );
    
  }
  
  
  FloatArray2AddToLast( output_data, predicted );
  FloatArray2AddToLast( output_data, actual );
  FloatArray2AddToLast( output_data, members );
  
  
  
}


void ConsolidateByClass(  FloatArray2 * consolidated, FloatArray2 * sorted_values  ){
  bool VERBOSE = false;
  int i, j , k;
  int L1 = sorted_values -> length;
  int f =  L1 - 1;
  int COL_VAL = 0, COL_CLS = 1;
  bool consolidate;
  float val_ths, val_prv = sorted_values -> get[0].get[COL_VAL];
  int cls_ths, cls_prv = sorted_values -> get[0].get[COL_CLS];
  int count = 0;
  if(VERBOSE)printf("\n");
  for( i = 0 ; i < L1; i++ ){
    val_ths = sorted_values -> get[i].get[ COL_VAL ];
    cls_ths = sorted_values -> get[i].get[ COL_CLS ];
    
    consolidate = ((val_ths != val_prv) || (cls_ths != cls_prv));
    if(consolidate){
      if(VERBOSE)printf("now\n");
      FloatArray2AddNew( consolidated , val_prv );
      FloatArray2AddToLast( consolidated ,  cls_prv );
      FloatArray2AddToLast( consolidated ,  count );
      count = 0;
      if(VERBOSE)printf("(%.2f,%i,%i)\n", val_ths, cls_ths, count );
    } else {
      if(VERBOSE)printf("(%.2f,%i,%i)\n", val_ths, cls_ths, count );
    }
    count++;
    val_prv = val_ths;
    cls_prv = cls_ths;
  }
  FloatArray2AddNew( consolidated , val_ths );
  FloatArray2AddToLast( consolidated ,  cls_ths );
  FloatArray2AddToLast( consolidated ,  count );
}


void ConsolidateByValue(  FloatArray2 * consolidated, FloatArray2 * sorted_values, int number_of_classes, FloatArray * buf  ){
  bool VERBOSE = false;
  int i, j , k;
  int L1 = sorted_values -> length;
  int COL_VAL = 0, COL_CLS = 1, COL_N = 2;
  float val_ths, val_nxt, val_prv = MIN;
  int n , cls_ths, cls_prv = sorted_values -> get[0].get[COL_CLS];
  FloatArray * counts = buf;
  FloatArrayReset( counts ); 
  FloatArrayInstantiate( counts , number_of_classes, 0.0f ); 
   
  
  if(VERBOSE)printf("\n");
  for( i = 0 ; i < L1; i++ ){
    val_ths = sorted_values -> get[i].get[ COL_VAL ];
    cls_ths = sorted_values -> get[i].get[ COL_CLS ];
    
    val_nxt = i + 1 >= L1 ? MIN : sorted_values -> get[i+1].get[ COL_VAL ];
    n       = sorted_values -> get[i].get[ COL_N ];
    
    if( val_prv != val_ths && val_ths != val_nxt ){
      if(VERBOSE)printf("clear!\n");
      FloatArrayFill( counts, 0.0f ); 
    }
    counts->get[cls_ths] =  sorted_values -> get[i].get[ 2 ];
    if(VERBOSE)printf("[%.2f,%i,%i]\n", val_ths, cls_ths, n ); 
    
    
    if( val_ths != val_nxt ){
      //printf("[!!!!!!!]\t(%.2f,%.2f,%.2f)\n", val_prv, val_ths, val_nxt );  
      //printf("[!!!!!!!]\n");
      if(VERBOSE)printf("[!!!!!!!] %i %i %i \n",(int) counts->get[0],(int) counts->get[1],(int) counts->get[2] );  
      FloatArray2AddNew( consolidated , val_ths );
      for( j = 0 ; j < counts->length; j++ ){
        FloatArray2AddToLast( consolidated ,  counts->get[j] );  
      }
    }
    
    val_prv = val_ths;
    cls_prv = cls_ths;
  }
  if(VERBOSE)FloatArray2PrintByRow( consolidated, consolidated->length); 
  
}




void JoinClassRatiosGreaterThan( FloatArray2 * intervals, FloatArray2 * floats , float ratio, FloatArray3 * buf3  ){
  bool VERBOSE = false;
  FloatArray3Reset( buf3 ); 
  FloatArray3AddNew( buf3 );
  FloatArray3AddNew( buf3 );
  FloatArray3AddNew( buf3 );
  FloatArray2 * buffer2A = &buf3->get[0];
  FloatArray2 * buffer2B = &buf3->get[1];
  FloatArray2 * buffer2C = &buf3->get[2];
  FloatArray2Reset( buffer2A ); 
  FloatArray2Reset( buffer2B ); 
  FloatArray2Reset( buffer2C ); 
  
  int L1 = floats ->length;
  int L2 = floats ->get[0].length;
  int from_col = 1;
  int to_col = L2 - 1;
  int number_of_classes = (to_col + 1) - from_col;
  FloatArray2 * ratios = buffer2A;
  FloatArray2Initialize2D1( ratios , number_of_classes );
  
  
  //float epsilon;
  
  int i, j;
  float cell_ratio;
  bool found;
  
  // - FIND ALL CELLS > RATIO
  // - even values represent rows
  // - odd values represent cols
  // i.e. [0] row, [1] col, [2] row, ...
  int index;
  if(VERBOSE)printf("FLAG ALL CELLS WITH VALUES OVER THE REQUIRED THRESHOLD...\n"); 
  for(i = 0 ; i < L1; i++ ){
    if(VERBOSE)printf("[%i]", i); 
    for(j = from_col; j < L2; j++){
      cell_ratio = FloatArrayGetRatioColFromTo(&floats->get[i], from_col, to_col , j ); 
      found = cell_ratio >= ratio;
      if( USE_SAMPLESIZE_MIN && found ){
        
        
      }
      if(VERBOSE)printf("\t%f", cell_ratio);   
      if(found){
        if(VERBOSE)printf("(!)");
        index = j - 1;
        FloatArrayAdd( &ratios->get[index], i );
        
      }else if(VERBOSE)printf(" ");
    }
    if(VERBOSE)printf("\n");
  }
  //FloatArray2Print( ratios );
  
  
  ////////////////////////////////////////////
  ///// get the indices of all contiguous spaces
  ////////////////////////////////////////////
  if(VERBOSE)printf("\nGET INDICES OF ALL CONTIGUOUS FLAGGED CELLS...\n"); 
  FloatArray2 * indices = buffer2B;
  int index1, index2;
  int index_this, index_prev;
  L1 = buffer2A -> length;
  bool within_bounds, final_index, indices_are_contiguous;
  for( i = 0 ; i < L1; i++ ){
    L2 = buffer2A ->get[i].length;
    index1 = index2 = buffer2A ->get[i].get[0];
    index_prev = index1;
    for( j = 1 ; j < L2; j++ ){
      index_this = buffer2A ->get[i].get[j];
      within_bounds = j != L2 - 1;
      final_index = j == L2 - 1;
      indices_are_contiguous = buffer2A ->get[i].get[j] == buffer2A ->get[i].get[j-1] + 1;
      if( within_bounds && indices_are_contiguous ){
        index2 = (int) buffer2A ->get[i].get[j];
        //printf("%i -> %i \t [%i,%i]\n", (int)buffer2A ->get[i].get[j-1], (int)buffer2A ->get[i].get[j], index1, index2);  
      } else {
        
        if( final_index && indices_are_contiguous ){ 
          index2 = buffer2A ->get[i].get[j]; }
        if(index1 != index2 ){
          FloatArray2AddNew( indices , index1 );
          FloatArray2AddToLast( indices , index2 );
          if(VERBOSE)printf("consolidate(%i %i)\n", index1, index2 ); 
        } 
        index1 = buffer2A ->get[i].get[j];
        index2 = buffer2A ->get[i].get[j];
      }
      
    }
  }
  
  
  
  //FloatArray2Print( indices );
  
  
  ////////////////////////////////////////////
  ///// add another col
  ////////////////////////////////////////////
  FloatArray2AddNew( buffer2C , 0.0f );
  FloatArray * row = &buffer2C->get[0];
  
  FloatArrayReset( row );
  FloatArray2GetCol( row , floats, 0 );
  FloatArray2InsertColEmpty( floats, 1 );
  FloatArrayOverwriteCol( floats , row, 1 );
  //FloatArray2PrintByRow( floats, floats ->length );
  ////////////////////////////////////////////
  ///// get the indices of all contiguous spaces -> consolidate
  ////////////////////////////////////////////
  
  int L3, k;
  int COL_VAL = 0;
  float val1, val2;
  L1 = indices->length;
  //FloatArray2Print( indices );
  for( i = L1 -1 ; i >= 0; i--){
    index1  = indices ->get[i].get[0];
    index2  = indices ->get[i].get[1];
    if(VERBOSE)printf("%i -> %i\n", index1, index2 );
    
    val1 = floats ->get[index1].get[ COL_VAL ];
    val2 = floats ->get[index2].get[ COL_VAL ];
    L2 = index2 + 1;
    
    
    
    
    for( j = index1 + 1 ; j < L2; j++ ){
      L3 = floats ->get[j].length;
      for( k = 0 ; k < L3; k++ ){
        floats ->get[ index1 ].get[ k ] += floats ->get[ j ].get[ k ];
      }
      floats ->get[ index1 ].get[ 0 ] = val1;
      floats ->get[ index1 ].get[ 1 ] = val2;
    }
    FloatArray2RemoveIndexFromTo( floats, index1 + 1 , index2, row );
  }
  if(VERBOSE)printf("\n"); 
  
  
  
  
  
  
  if( !USE_SAMPLESIZE_MIN ){
    FloatArray2CopyToFrom2( intervals, floats );
    
  } else {
    
    
    
    // only grab those which meet threshold parameters
    FloatArray2PrintByRow( floats, floats ->length );
    printf("\n\n");
    FloatArray * fa;
    L1 = floats->length;
    int total;
    for( int i = 0 ; i < L1; i++ ){
      fa = &floats->get[i];
      index = FloatArrayGetIndexOfMax( fa );
      total = fa->get[ index ];
      FloatArray2Add( intervals , fa  );
      //total >= SAMPLE_SIZE_MIN
      //printf("total = %i\n", total );
    }
  }
}


void FloatArrayGetClassCounts( FloatArray * counts, FloatArray2 * values, int n_classes ){
  FloatArrayInstantiate( counts , n_classes , 0.0f);
  int i;
  int COL_CLASS_ENUMS = values -> length -1 ;
  int L1 = values -> get[ COL_CLASS_ENUMS ].length;
  int cls;
  for( i = 0 ; i < L1; i++ ){
    cls = values ->get[ COL_CLASS_ENUMS ].get[i];
    counts ->get[ cls ] ++;
  }
} 

void KSplitRatio( FloatArray3 * splits, FloatArray2 * values, int K , int n_classes, FloatArray * buffer ){
  bool VERBOSE = false;
  FloatArray3Instantiate2D1( splits, K ); 
  FloatArrayReset( buffer ); 
  
  // get the quanity of each class
  FloatArrayGetClassCounts( buffer , values, n_classes ); 
  if(VERBOSE)FloatArrayPrintfBr( buffer, "%.2f ", 0 ); 
  int COL_CLASS_ENUM = values ->length - 1;
  int L1 = n_classes;
  float chunk_size[ L1 ];
  float totals[ L1 ];
  ////////////////////////////////////
  
  // get the size of each chunk
  int i;
  for( i = 0 ; i < L1; i++ ){
    totals[i]     = buffer ->get[ i ];
    chunk_size[i] = (int) buffer ->get[ i ] / K;
    //printf("%.2f ", chunk_size[i] ); 
  }
  if(VERBOSE)printf("\n"); 
  ////////////////////////////////////
  FloatArrayReset(buffer); 
  FloatArray * class_enums = buffer;
  FloatArrayCopyFromTo( &values->get[COL_CLASS_ENUM], class_enums );
  ////////////////////////////////////
  FloatArray2 * fold_x;
  L1 = K;
  int L2 = n_classes;
  int L3;
  int j, k;
  int cls, cls_srch;
  bool found;
  int added;
  int total;
  int index;
  
  
  FA2PrintL( values );
  // values->length : the number of dimensions
  for(i = 0 ; i < L1; i++ ){ // L1 = n_classes
    fold_x = &splits ->get[i];
    FloatArray2Initialize2D1( fold_x , values->length );
    if(VERBOSE)printf("adding to split %i: ", i); 
    
    for(j = 0 ; j < L2; j++ ){
      cls = j;
      if(VERBOSE)printf("\nclass %i:", cls); 
      added = 0;
      L3 = class_enums -> length;
      added = 0;
      total = chunk_size[cls];
      for( k = 0 ; k < L3; k++ ){
        cls_srch = class_enums ->get[k];
        found = cls == cls_srch;
        if( found ){
          
          added++;
          totals[ cls ]--;
          
          if(VERBOSE)printf("\n[found at row: %i](%i)(%i)\n", k, cls ,cls_srch  );
          class_enums ->get[k] = -1;
          index = k;
          
          // values->get[ 0 ].get[ index ]
          
          //FloatArray2Constr(fold_x);
          for(int l = 0 ; l < values ->length; l++ ){
            
            FloatArrayAdd( &fold_x->get[l], values->get[ l ].get[ index ] );
            if(VERBOSE)printf("{%i}", l);
            
            
          }
          //
          
          
          //FloatArray2COLAddRowFA2COL( fold_x , values, index );
          
          //    printf("adding class %i to fold %i\n", cls, i); 
          //    class_enums ->get[k] = -1.0f;
        }
        if( added >= total) break;
        //if(fold_x->get[cls].length >= chunk_size[cls] ) break;
      }
    }
    if(VERBOSE)printf("\n"); 
  }
  //for( i = 0 ; i < n_classes; i++ ){
  //  printf("%.2f ", totals[cls] ); 
  //}
  
}



void KFoldValidation(FloatArray3 * kfoldsplit, FloatArray3 * classify, FloatArray2 * data_by_col_train , FloatArray * scores, int number_of_dimensions, int number_of_classes, FloatArray3 * bufferFA3A, FloatArray3 * bufferFA3B ,  FloatArray * bufferFA1, String * out ){
  
  FloatArray2  *data_by_col_test;
  
  
  
  int i , j , k;
  int L1 = kfoldsplit -> length; 
  FloatArray2 * test, * train;
  for(i = 0 ; i < L1; i++ ){
    FloatArray2Reset( data_by_col_train ); 
    data_by_col_test = &kfoldsplit ->get[i];
    for( j = 0 ; j < L1; j++ ){
      if( i == j )  continue;
      train = &kfoldsplit ->get[j];  
      FloatArray2CopyToFrom2( data_by_col_train, train );
    }
    //printf("----------------------------------------------------\n");
    //printf("\t\t\t TEST(%i)\n", i );
    //printf("----------------------------------------------------\n");
    FloatArray3Reset( classify); 
    FloatArray3Reset( bufferFA3A ); 
    FloatArray3Reset( bufferFA3B ); 
    BuildClassifer( classify, data_by_col_train, number_of_dimensions, number_of_classes, ACCURACY, bufferFA3A, bufferFA3B, out );
    
    FloatArrayReset( bufferFA1 ); 
    //FloatArray3PrintTables( classify , 5 );
    OutFloatArray3Table( "test", classify, out );
    
    float score = ValidateClassifier( classify, data_by_col_test, number_of_classes , bufferFA1); 
    FloatArrayAdd( scores, score );
    printf("SCORE: %f\n", score ); 
  }
  printf("----------------------------------------------------\n");
  float total;
  total = FloatArrayTotalFrom(scores, 0 );
  total /= (float) scores->length;
  printf("TOTAL: %f\n",  total ); 
}


float ValidateClassifier( FloatArray3 * classifier, FloatArray2 * testing_data, int number_of_classes, FloatArray * buf  ){
  bool VERBOSE = SHOW_CLASSIFIER_OUTPUT;
  FloatArray2 * output_data = FloatArray3Next( &ERROR_LOG );
  
  FloatArray * totals = buf;
  FloatArrayReset( totals );
  FloatArrayInitialize( totals, number_of_classes );
  
  int L1 = testing_data ->length - 1;
  int L2 = testing_data ->get[ 0 ].length;
  int actual_class, predicted_class;
  int col, row;
  int good, bad;
  int max, success = 0, ttl = 0;
  int members, m1, m2;
  char * outcome;
  float val;
  int i , j , k;
  for( j = 0 ; j < L2; j++ ){
    //break;
    FloatArrayFill( totals, 0.0f );
    row = j;
    actual_class = GetActualClass( testing_data, row ); 
    for( i = 0 ; i < L1; i++ ){
      col = i;
      // 4
      // 6 8
      //if( i == 0 || i == 4   ) continue; //HERE
      val = testing_data ->get[ col ].get[ row ];
      predicted_class = GetPredictedClass( classifier , col, val );
      
      //members = GetTotalClassMembers( classifier , col, val  ); 
      //members = GetActualClassMembers( classifier, col, val, actual_class ); 
      //members = 1;
      m1 = GetActualClassMembers( classifier, col, val, predicted_class ); 
      m2 = GetTotalClassMembers( classifier , col, val  ) - m1;
      members = m2 == 0 ? m1 : m1 / m2;
      //members = 1;
      outcome = predicted_class == actual_class ? "T" : "F";
      

      if( predicted_class != -1 ) totals ->get[ predicted_class ] +=  1;  
      
      // OUTPUT 
      //if(  predicted_class == -1 || predicted_class != actual_class ) RecordClassifierFails( classifier, output_data, col , val, predicted_class, actual_class , members ); 
      
      
      
      if(VERBOSE)printf("VAL: %.2f \t DIM: %i \t PRD: %i \t ACT: %i \t(%i) \t%s\n", val, col, predicted_class, actual_class, members , outcome );
    }
    
    
    max = FloatArrayGetMax( totals );
    predicted_class = FloatArrayGetIndexFirstOccurance( totals, max );
    
    outcome = predicted_class == actual_class ? "YES" : "NO";
    if(VERBOSE)printf("------------------------------------------\n"); 
    if(VERBOSE)printf("[%i] %.2f \t\t\t PRD: %i \t ACT: %i \t %s\n", j , val, predicted_class, actual_class, outcome  ); 
    if(VERBOSE)printf("------------------------------------------\n"); 
    
    if( predicted_class == actual_class ) success += 1;
    ttl++;
  }
  float score =  (float)success/ ttl;
  if(VERBOSE || SHOW_CLASSIFIER_SCORE )printf("success: (%i/%i) = %.2f\n",  success, ttl, score ); 
  if(VERBOSE)printf("------------------------------------------\n"); 
  return score;
}

void OutFloatArray2COLRowSp( char * title , FloatArray2 * data, int space, String * out ){
  StringAddTitle(  title , out ); 
  StringAddFloatArray2( data , out ); 
  StringAddLine(  space , out );
}

void OutFloatArray2COLRow( char * title , FloatArray2 * data, String * out ){
  OutFloatArray2COLRowSp( title, data, 4, out ); 
}


void OutFA3C( FloatArray3 * cols, String * out  ){
  int i, j;
  FloatArray2 * tableX;
  for( i = 0 ; i < cols->length; i++){
    tableX = &cols->get[i];
    for(j = 0 ; j < tableX->length; j++ ){
      FloatArrayToStringf( &tableX->get[j], "%.2f\t", out );  
      StringAddLine(  1 , out );
    }
    StringAddLine(  1 , out );
  }
  
  
}

void OutFloatArray3Table( char * title , FloatArray3 * data, String * out ){
  int i;
  int L1 = data->length;
  for(i = 0 ; i < L1; i++ ){
    StringAddSubtitleInt("\nDIMENSION ", i,  out );
    OutFloatArray2COLCol( "", &data ->get[i], out ); 
    
  }
  
}
void OutFloatArray2COLCol( char * title, FloatArray2 * cols, String * out  ){
  
  StringAddTitle(  title , out ); 
  int i, j , k;
  for(i = 0 ; i < cols->length; i++ ){
    FloatArrayToStringf( &cols->get[i], "%.2f ", out );  
    StringAddLine(  1 , out );
  }
  StringAddLine(  4 , out );
}

FloatArray3 * allocate_float_memory(){        FloatArray3Constr( &FLOATS );   return &FLOATS;}
FloatArray3 * allocate_float_memory2(){       FloatArray3Constr( &FLOATS2 );  return &FLOATS2;}
FloatArray3 * allocate_float_memory3(){       FloatArray3Constr( &FLOATS3 );  return &FLOATS3;}
FloatArray3 * allocate_float_memory4(){       FloatArray3Constr( &FLOATS4 );  return &FLOATS4;}
FloatArray3 * allocate_float_memory5(){       FloatArray3Constr( &FLOATS5 );  return &FLOATS5;}
FloatArray3 * allocate_float_memory6(){       FloatArray3Constr( &FLOATS6 );  return &FLOATS6;}
FloatArray3 * allocate_error_log(){           FloatArray3Constr( &ERROR_LOG );return &ERROR_LOG;}
StringArray * allocate_stringarray_memory1(){ StringArrayConstr( &STRINGS1 ); return &STRINGS1;}
StringArray * allocate_stringarray_memory2(){ StringArrayConstr( &STRINGS2 ); return &STRINGS2;}
StringArray * allocate_stringarray_memory3(){ StringArrayConstr( &STRINGS3 ); return &STRINGS3;}
StringArray * allocate_stringarray_memory4(){ StringArrayConstr( &STRINGS4 ); return &STRINGS4;}
String      * allocate_string_memory1(){      StringConstr( &STRING1, 1000 ); return &STRING1;}
String      * allocate_string_memory2(){      StringConstr( &STRING2, 1000 ); return &STRING2;}
String      * allocate_string_memory3(){      StringConstr( &STRING3, 1000 ); return &STRING3;}
String      * allocate_string_memory4(){      StringConstr( &STRING4, 1000 ); return &STRING4;}



void GetPredictionVectorArray( FloatArray2 * prediction_vector_array, FloatArray3 * classify, FloatArray2 * data_by_col_test ){
  FloatArray * prediction_vector; FloatArray BUF; FloatArrayConstr( &BUF ); prediction_vector = &BUF; 
  float val;
  int predicted_class;
  int i, j , L1 = data_by_col_test->length, L2 = data_by_col_test->get[0].length;
  float vote_val, vote_weight;
  for( j = 0 ; j < L2; j++ ){
    FloatArrayReset( prediction_vector );
    for( i = 0 ; i < L1; i++ ){
      val = data_by_col_test ->get[ i ].get[ j ];
      predicted_class = GetPredictedClass( classify , i, val );
      if( predicted_class == -1 ){ FloatArrayAdd( prediction_vector, 9 ); continue; } 
      else { FloatArrayAdd( prediction_vector, predicted_class ); }
    }
    FloatArray2Add( prediction_vector_array, prediction_vector ); 
    
  }
  
  FloatArrayFree( prediction_vector ); 
} 



void getVectorPredictionClassTotals( FloatArray2 * votes, FloatArray2 * prediction_vector, int number_of_classes ){
  bool VERBOSE = false;
  int i , j , k;
  int L1 = prediction_vector ->length;
  int L2 = prediction_vector->get[0].length;
  int cls, index;
  int vote;
  FloatArray BUF; FloatArray * buf = &BUF; FloatArrayConstr( buf ); 
  FloatArray * vector;
  for( i = 0 ; i < L1; i++ ){
    vector = &prediction_vector ->get[i];
    FloatArrayInstantiate( buf, number_of_classes, 0.0 );
    for( j= 0 ; j < L2; j++ ){
      cls = vector->get[j];
      buf->get[cls]++;
    }
    FloatArray2Add( votes, buf ); 
  }
  FloatArrayFree( buf ); 
}

void GetPredictionVector( FloatArray * prediction_vector, FloatArray2 * prediction_vector_array, int number_of_classes, FloatArray * buf ){
  bool VERBOSE = false;
  int cls, vote;
  int i , j , k;
  int L1 = prediction_vector_array ->length, L2;
  FloatArray * votes = buf;
  for( i = 0 ; i < L1; i++ ){
      FloatArrayInstantiate( votes, number_of_classes, 0.0 );
      L2 = prediction_vector_array ->get[i].length;
      for( j = 0 ; j < L2; j++ ){
          cls = prediction_vector_array->get[i].get[j];
          votes->get[cls]++;
      }
      vote = FloatArrayGetIndexOfMax( votes );
      if(VERBOSE)FAPrintf( votes, "%2.0f"); 
      if(VERBOSE)printf("%i\n", vote );
      FloatArrayAdd( prediction_vector, vote );
  }
}


void GetPredictionVectorAug( FloatArray * prediction_vector, FloatArray2 * prediction_vector_array, FloatArray2 * override, int number_of_classes, FloatArray * buf, FloatArray * actual_vector ){
  bool VERBOSE = false;
  bool found; 
  int count;
  int cls, vote;
  int i , j , k;
  int L1 = prediction_vector_array ->length, L2;
  FloatArray * votes = buf;
  FloatArray2 * fn = override;
  FloatArray * pattern, * vector;
  int col1, col2, val1, val2, indx;
  for( i = 0 ; i < L1; i++ ){
    FloatArrayInstantiate( votes, number_of_classes, 0.0 );
    
    
    L2 = prediction_vector_array ->get[i].length;
    for( j = 0 ; j < L2; j++ ){
      cls = prediction_vector_array->get[i].get[j];
      votes->get[cls]++;
    }
    vote = FloatArrayGetIndexOfMax( votes );
    
    vector = &prediction_vector_array->get[i]; if(VERBOSE)FAPrintf( vector, "%.0f"); if(VERBOSE)printf("\t[%i]", vote );
    if( vote == 0 ){
        count = 0;
        L2 = override ->length;
        for( j = 0 ; j < L2; j++ ){
          pattern = &override->get[ j ];
          col1 = pattern->get[ 0 ];
          col2 = pattern->get[ 1 ];
          val1 = pattern->get[ 2 ];
          val2 = pattern->get[ 3 ];
          indx = pattern->get[ 4 ];
          found = (vector->get[ col1 ] == val1) && (vector->get[ col2 ] == val2);
          if(found){
            if(VERBOSE)printf("\n\t[ %2.0f %2.0f %2.0f %2.0f ]", (float)col1, (float)col2, (float)val1, (float)val2 );
            if(VERBOSE)FAPrintf( &prediction_vector_array->get[indx], "%.0f"); 
            if(VERBOSE)printf("{%i}",  (int)actual_vector->get[i] );
            count++;
          } 
        }
        if(found){
          if(VERBOSE)printf("\n-> (%i) -> [1]\t{%i}", count, (int)actual_vector->get[i] );
          vote = 1;
        }
    }
    if(VERBOSE)printf("\n"); 
    
    FloatArrayAdd( prediction_vector, vote );
  }
}



void SortPredictionVectorArray( FloatArray2 * prediction_vector_array_sorted, FloatArray2 * prediction_vector_array, int number_of_dimensions, FloatArray3 * index_hier0, FloatArray3 * index_hier1 ){
  
  bool VERBOSE = false;
  int i , j;
  int i1, i2;
  int COL = -1;
  char tst;
  
  FloatArray3Reset( index_hier0 ); 
  FloatArray3Reset( index_hier1 ); 
  FloatArray3 * fa3p, *fa3q;
  FloatArray2 * fa2; 
  FloatArray * fa;//,* faB,* faC, *faX;
  float val;
  int index;
  int L1 = number_of_dimensions;
  int L2, L3;
  COL = 0;
  
  int col = 0;
  int size1, size2;
  FloatArray3Add( index_hier0 , prediction_vector_array ); 
  for( int c = 0; c < number_of_dimensions; c++ ){
    if ( c % 2 != 0 ){
      fa3q = index_hier0;
      fa3p = index_hier1;
    }else{ 
      fa3q = index_hier1;
      fa3p = index_hier0;
    } 
    col = c;
    
    
    if(VERBOSE)printf("sorting at col %i\n", c );
    
    for( i = 0 ; i < fa3p->length; i++ ){
      //printf("-----------------\n");
      //printf("LEVEL: %i\n", c );
      //printf("-----------------\n");
      
      
      FloatArray3AddEmpty( fa3q );
      fa2 = &fa3q ->get[ fa3q ->length - 1 ];
      size1 = fa3q->get[fa3q->length-1].length;
      for( j = 0 ; j < fa3p->get[i].length; j++ ){
        //printf("TYPE: %i, INDICES: ", j );
        val = fa3p->get[i].get[j].get[col];
        fa = &fa3p->get[i].get[j];
        if( val == 0 ){
          FloatArray2Add( fa2, fa );
        }
      }
      size2 = fa3q->get[fa3q->length-1].length;
      if( size1 == size2 ){ fa3q->length--;}
      
      
      
      FloatArray3AddEmpty( fa3q );
      fa2 = &fa3q ->get[ fa3q ->length - 1 ];
      size1 = fa3q->get[fa3q->length-1].length;
      for( j = 0 ; j < fa3p->get[i].length; j++ ){
        //printf("TYPE: %i, INDICES: ", j );
        val = fa3p->get[i].get[j].get[col];
        fa = &fa3p->get[i].get[j];
        if( val == 1 ) FloatArray2Add( fa2, fa );
      }
      size2 = fa3q->get[fa3q->length-1].length;
      if( size1 == size2 ){ fa3q->length--;}
      
      
      
      
      FloatArray3AddEmpty( fa3q );
      fa2 = &fa3q ->get[ fa3q ->length - 1 ];
      size1 = fa3q->get[fa3q->length-1].length;
      for( j = 0 ; j < fa3p->get[i].length; j++ ){
        //printf("TYPE: %i, INDICES: ", j );
        val = fa3p->get[i].get[j].get[col];
        fa = &fa3p->get[i].get[j];
        if( val >= 2 ) FloatArray2Add( fa2, fa );
      }
      size2 = fa3q->get[fa3q->length-1].length;
      if( size1 == size2 ){ fa3q->length--;}
      
    }
    FloatArray3Reset( fa3p );
    
    
    
    //if( c == 4 ) break;
  }
  
  for( i = 0 ; i < fa3q->length; i++ ){
    for( j = 0 ; j < fa3q->get[i].length; j++ ){
      FloatArray2Add( prediction_vector_array_sorted, &fa3q->get[i].get[j] ); 
    }
  } 
  
}


void FloatArray3AddView( FloatArray3 * to, FloatArray2 * from ){
  FloatArray3Add( to, from );
  int max = MIN, len;
  int i = 0, L = to->length;
  for( i = 0 ; i < L; i++ ){
    len = to -> get[i].length;
    if( len > max ) max = len;
  }
  
  for( i = 0 ; i < L; i++ ){
    len = to -> get[i].length;
    if( len < max ){
      while( to->get[i].length < max  ){
        FloatArray2AddEmpty( &to->get[i] ); 
      }
    };
  }
  
}



void FA2CountColumnsEqualTo( FloatArray * cases, FloatArray2 * data, float equal_to, int number_of_dimensions ){
  // DESC: count the number of columns equal to x (the variable equal_to) for all rows
  // RETURNS: a vector containing the occurances of each value. 
  //    for example let x = 5, and let column-1, column-2, and column-3 contain x 
  //    a total of 7 times, 4 times, and 9 times, respectively. 
  //    this would return the vector [ 7 , 4, 9 ];
  
  FloatArrayInstantiate( cases, number_of_dimensions - 1, 0.0f );
  
  int d = number_of_dimensions - 1;
  float val, test_val = equal_to; // test for false negatives
  int i , j, L2 = d, L = data -> length;
  for( i = 0 ; i < L; i++ ){
    for( j = 0 ; j < L2; j++ ){
      val = data -> get[i].get[j];
      val = val == test_val ? 1 : 0;
      cases->get[j] += val;
    }
  }
}

// this assumes all paterns are uiversal
// some paterns might exist in some cases 

// find patterns that exist in which 
// A: exist in the correct prediction, do not exist is false prediction
// B: Get all patterns that exist in correct prediction
// C: Get all patterns that exist in incorrect prediction
// D: get all patterns that exist in both, then remove them from both
// E: should have patterns that exist in only 1, and not the other

// under what circumstances does a a successful prediction appear

// any combination of columns that have a value only when a successful predection occurs but not necessarily every every successful prediction
// for example: 
// prediction: 0 -> 

// the only time combination-x appears, is under the condition of a false negative

// combination that appear only when a false negative

void FA2SeqBinary( FloatArray2 * flt2, int array_length ){
  FloatArray *prv;
  FloatArray *flt;
  
  flt = FloatArray2Next( flt2 ); FloatArrayInstantiate( flt, array_length, 0.0f);
  flt = FloatArray2Next( flt2 ); FloatArrayInstantiate( flt, array_length, 0.0f); 
  
  int index1 = -1, index2 = flt->length - 1, one = 1, zro = 0;
  int j =  flt->length - 1;
  float val;
  int prev;
  int L = flt->length;
  int i = 0;
  int count = 1;
  
  //FAPrintfln(flt, "%.0f"); 
  
  while( true ){
    count++;
    for(int j = L - 1; j >= 0 ; j-- ){
      val = flt->get[j];
      if( val == zro ){ 
        index2 = j;
        flt->get[j] = 1;
        for(int k = j + 1 ; k < L; k++ ){
          flt->get[k] = 0;
        }
        break;
      }
    }
    prv = flt;
    flt = FloatArray2Next( flt2 ); 
    FloatArrayCopyToFrom( flt, prv );
    //FAPrintfln(prv, "%.0f"); 
    int i;
    for( i = 0 ; i < L ; i++ ){
      val = prv->get[i];
      if(val == 0.0f) break;
    }
    if( i == L ) break;
    
  }
  
  flt2->length --;
}

void PatternsRemDup( FloatArray2 * data ){
  FloatArray * previous = FloatArray2Next( data ); 
  
  data->length--;
  int i, j, k = 0, L = data->length, L2 = data->get[0].length;
  bool equal;
  FloatArrayInstantiate( previous, L2, 0.0f );
  for(i = 0 ; i < 70; i++ ){
    //FAPrintf(previous, "%3.0f" ); printf("\t");
    FAPrintf( &data->get[i], "%3.0f" ); 
    //FloatArrayReset( previous );
    //FloatArrayCopyToFrom( previous,  &data->get[i] );
    
    /*
    for(j = 0 ; j < L2; j++ ){
    equal = data->get[i].get[j] == previous->get[j];
    if( !equal ){
    FloatArrayReset( previous );
    FloatArrayCopyToFrom( previous,  &data->get[i] );
    FloatArrayReset( &data->get[k] );
    FloatArrayCopyToFrom( &data->get[k],  &data->get[i] );
    printf("\t(%i)->%i ", i, k ); 
    k++;
    break;
    };
    
    }*/
    
    printf("\n");
    
  }
  data->length = k;
  }



void PatternsGet2V0( FloatArray2 * patterns, FloatArray2 * data, int number_of_dimensions , FloatArray2 * bufferFA2  ){
  
  bool VERBOSE = false;
  FloatArray2 * indics = bufferFA2;
  FloatArray2Reset( bufferFA2 ); 
  
  FloatArray2 * A = data;
  int L = number_of_dimensions;
  int L2 = A->length;
  float val;
  int col1, col2, val1, val2;
  
  for( int i = 0 ; i < L; i++ ){
    for( int j = i + 1; j < L; j++ ){ // i + 1, then dont need if( i == j ) continue
      col1 = i;
      col2 = j;
      FloatArray2AddEmpty( indics ); 
      FloatArray2AddToLast( indics, col1 ); 
      FloatArray2AddToLast( indics, col2 );
      if(VERBOSE)printf("(%i,%i)", col1, col2);
    }
    if(VERBOSE)printf("\n");
  }
  
  L = indics->length;
  bool zz, zo, oz, oo, all;
  for( int i = 0 ; i < L; i++ ){
    
    col1 = indics->get[i].get[0];
    col2 = indics->get[i].get[1];
    
    L2 = data->length;
    all = zz = zo = oz = oo = false;
    
    for( int j = 0 ; j < L2; j++ ){
      val1 = data->get[j].get[col1];
      val2 = data->get[j].get[col2];
      FloatArray2AddEmpty(  patterns ); 
      FloatArray2AddToLast( patterns, col1 ); 
      FloatArray2AddToLast( patterns, col2 );
      FloatArray2AddToLast( patterns, val1 ); 
      FloatArray2AddToLast( patterns, val2 );
    }
    
  }
}

FloatArray2 * PatternsGet2V( FloatArray2 * data, int number_of_dimensions , FloatArray3 * memoryFA3 ){
  
  bool VERBOSE = false;
  FloatArray2 * patterns = FloatArray3Next( memoryFA3 );
  FloatArray2 * indics = FloatArray3Next( memoryFA3 );
  
  
  FloatArray2 * A = data;
  int L = number_of_dimensions - 1;
  int L2 = A->length;
  float val;
  int col1, col2, val1, val2;
  
  for( int i = 0 ; i < L; i++ ){
    for( int j = i + 1; j < L; j++ ){ // i + 1, then dont need if( i == j ) continue
      col1 = i;
      col2 = j;
      FloatArray2AddEmpty( indics ); 
      FloatArray2AddToLast( indics, col1 ); 
      FloatArray2AddToLast( indics, col2 );
      if(VERBOSE)printf("(%i,%i)", col1, col2);
    }
    if(VERBOSE)printf("\n");
  }
  
  L = indics->length;
  bool zz, zo, oz, oo, all;
  for( int i = 0 ; i < L; i++ ){
    
    col1 = indics->get[i].get[0];
    col2 = indics->get[i].get[1];
    
    L2 = data->length;
    all = zz = zo = oz = oo = false;
    
    for( int j = 0 ; j < L2; j++ ){
      val1 = data->get[j].get[col1];
      val2 = data->get[j].get[col2];
      FloatArray2AddEmpty(  patterns ); 
      FloatArray2AddToLast( patterns, col1 ); 
      FloatArray2AddToLast( patterns, col2 );
      FloatArray2AddToLast( patterns, val1 ); 
      FloatArray2AddToLast( patterns, val2 );
    }
    
  }
  
  FloatArray2Reset( indics );
  //memoryFA3->length--;
  return patterns;
}


void PatternsGetSet2V0( FloatArray2 * patterns, FloatArray2 * data, int number_of_dimensions , FloatArray2 * bufferFA2 ){
  
  bool VERBOSE = false;
  FloatArray2Reset( bufferFA2 );
  FloatArray2 * indics = bufferFA2;
  FloatArray2 * A = data;
  int L = number_of_dimensions - 1;
  int L2 = A->length;
  float val;
  int col1, col2, val1, val2;
  
  for( int i = 0 ; i < L; i++ ){
    for( int j = i + 1; j < L; j++ ){ // i + 1, then dont need if( i == j ) continue
      col1 = i;
      col2 = j;
      FloatArray2AddEmpty( indics ); 
      FloatArray2AddToLast( indics, col1 ); 
      FloatArray2AddToLast( indics, col2 );
      if(VERBOSE)printf("(%i,%i)", col1, col2);
    }
    if(VERBOSE)printf("\n");
  }
  
  L = indics->length;
  bool zz, zo, oz, oo, all;
  int a, b, c, d;
  for( int i = 0 ; i < L; i++ ){
    
    col1 = indics->get[i].get[0];
    col2 = indics->get[i].get[1];
    
    L2 = data->length;
    all = zz = zo = oz = oo = false;
    a = -1, b = -1, c = -1, d = -1;
    for( int j = 0 ; j < L2; j++ ){
      val1 = data->get[j].get[col1];
      val2 = data->get[j].get[col2];
      if(VERBOSE)printf("(%i,%i,%i,%i)", col1, col2, val1, val2 );
      if(VERBOSE)printf("\n"); 
      if( val1 == 0 && val2 == 0 ){ zz = true; a = j; } else 
      if( val1 == 0 && val2 == 1 ){ zo = true; b = j; } else
      if( val1 == 1 && val2 == 0 ){ oz = true; c = j; } else
      if( val1 == 1 && val2 == 1 ){ oo = true; d = j; }
            
      all = zz == zo == oz == oo == true;
            
      if( all ) break;
            
            
            
    }
    //printf("%i,%i,%i,%i\n", zz, zo, oz, oo );
    if( zz ){ 
      FloatArray2AddEmpty(  patterns ); 
      FloatArray2AddToLast( patterns, col1 ); 
      FloatArray2AddToLast( patterns, col2 );
      FloatArray2AddToLast( patterns, 0 ); 
      FloatArray2AddToLast( patterns, 0 );
      //FloatArray2AddToLast( patterns, a );
    }
    if( zo ){ 
      FloatArray2AddEmpty( patterns ); 
      FloatArray2AddToLast( patterns, col1 ); 
      FloatArray2AddToLast( patterns, col2 );
      FloatArray2AddToLast( patterns, 0 ); 
      FloatArray2AddToLast( patterns, 1 );
      //FloatArray2AddToLast( patterns, b );
    }
    if( oz ){ 
      FloatArray2AddEmpty( patterns ); 
      FloatArray2AddToLast( patterns, col1 ); 
      FloatArray2AddToLast( patterns, col2 );
      FloatArray2AddToLast( patterns, 1 ); 
      FloatArray2AddToLast( patterns, 0 );
      //FloatArray2AddToLast( patterns, c );
    }
    if( oo ){ 
      FloatArray2AddEmpty( patterns ); 
      FloatArray2AddToLast( patterns, col1 ); 
      FloatArray2AddToLast( patterns, col2 );
      FloatArray2AddToLast( patterns, 1 ); 
      FloatArray2AddToLast( patterns, 1 );
      //FloatArray2AddToLast( patterns, d );
    }
  }
}
FloatArray2 * PatternsGetSet2V( FloatArray2 * data, int number_of_dimensions , FloatArray3 * memoryFA3 ){
  
  bool VERBOSE = false;
  FloatArray2 * patterns = FloatArray3Next( memoryFA3 );
  FloatArray2 * indics = FloatArray3Next( memoryFA3 );
  
  
  FloatArray2 * A = data;
  int L = number_of_dimensions - 1;
  int L2 = A->length;
  float val;
  int col1, col2, val1, val2;
  
  for( int i = 0 ; i < L; i++ ){
    for( int j = i + 1; j < L; j++ ){ // i + 1, then dont need if( i == j ) continue
      col1 = i;
      col2 = j;
      FloatArray2AddEmpty( indics ); 
      FloatArray2AddToLast( indics, col1 ); 
      FloatArray2AddToLast( indics, col2 );
      if(VERBOSE)printf("(%i,%i)", col1, col2);
    }
    if(VERBOSE)printf("\n");
  }
  
  L = indics->length;
  bool zz, zo, oz, oo, all;
  for( int i = 0 ; i < L; i++ ){
    
    col1 = indics->get[i].get[0];
    col2 = indics->get[i].get[1];
    
    L2 = data->length;
    all = zz = zo = oz = oo = false;
    
    for( int j = 0 ; j < L2; j++ ){
      val1 = data->get[j].get[col1];
      val2 = data->get[j].get[col2];
      if(VERBOSE)printf("(%i,%i,%i,%i)", col1, col2, val1, val2 );
      if(VERBOSE)printf("\n"); 
      if( val1 == 0 && val2 == 0 ){ zz = true; } else 
        if( val1 == 0 && val2 == 1 ){ zo = true; } else
          if( val1 == 1 && val2 == 0 ){ oz = true; } else
            if( val1 == 1 && val2 == 1 ){ oo = true; }
            
            all = zz == zo == oz == oo == true;
            
            if( all ) break;
            
            
            
    }
    //printf("%i,%i,%i,%i\n", zz, zo, oz, oo );
    if( zz ){ 
      FloatArray2AddEmpty(  patterns ); 
      FloatArray2AddToLast( patterns, col1 ); 
      FloatArray2AddToLast( patterns, col2 );
      FloatArray2AddToLast( patterns, 0 ); 
      FloatArray2AddToLast( patterns, 0 );
    }
    if( zo ){ 
      FloatArray2AddEmpty( patterns ); 
      FloatArray2AddToLast( patterns, col1 ); 
      FloatArray2AddToLast( patterns, col2 );
      FloatArray2AddToLast( patterns, 0 ); 
      FloatArray2AddToLast( patterns, 1 );
    }
    if( oz ){ 
      FloatArray2AddEmpty( patterns ); 
      FloatArray2AddToLast( patterns, col1 ); 
      FloatArray2AddToLast( patterns, col2 );
      FloatArray2AddToLast( patterns, 1 ); 
      FloatArray2AddToLast( patterns, 0 );
    }
    if( oo ){ 
      FloatArray2AddEmpty( patterns ); 
      FloatArray2AddToLast( patterns, col1 ); 
      FloatArray2AddToLast( patterns, col2 );
      FloatArray2AddToLast( patterns, 1 ); 
      FloatArray2AddToLast( patterns, 1 );
    }
  }
  FloatArray2Reset( indics );
  //memoryFA3->length--;
  return patterns;
}



/*
void OutAdd( char * str, String * out ){
StringAppendString2( out , str );
}


void OutAddBlockTitleInt( char * title, int num, String * out ){
char buf[10];
sprintf( buf, "%i", num ); 
StringAppendString2( out , "-------------------------------------------------------------------\n");
StringAppendString2( out , title );
StringAppendString2( out , buf );
StringAppendString2( out , "\n");
StringAppendString2( out , "-------------------------------------------------------------------\n");
}

void OutAddSubtitle( char * title, String * out ){
StringAppendString2( out , title );
StringAppendString2( out , "\n");
}

void OutAddSectionFA( FloatArray * array, char * title, String * out ){

float val;
int j, k;
StringAddTitle(  title , out ); 
for( j = 0 ; j < array->length; j++ ){
val = array->get[j];
floatToStringf( val , "%.2f ", out);     
StringAppendChar( out ,'\n');
}
StringAddLine(  4 , out );

}

void OutAddSectionFA2( FloatArray2 * array, char * title, String * out ){

float val;
int j, k;
StringAddTitle(  title , out ); 
for( j = 0 ; j < array->length; j++ ){
for( k = 0 ; k < array->get[j].length; k++ ){
val = array->get[j].get[k];
floatToStringf( val , "%.2f ", out);        
}
StringAppendChar( out ,'\n');
}
StringAddLine(  4 , out );

}


void OutFloatArray3Table( char * title , FloatArray3 * data, String * out ){
int i;
int L1 = data->length;
for(i = 0 ; i < L1; i++ ){
StringAddSubtitleInt("\nDIMENSION ", i,  out );
OutFloatArray2COLCol( "", &data ->get[i], out ); 

}

}




void FloatArray3GetClassesByColumns( FloatArray3 * classes_in_columns, FloatArray2 * values_in_columns, FloatArray2 * class_indices, int number_of_classes, FloatArray * buffer ){
int i, j , k;
FloatArray2 * this;
int class_enum;
for(i = 0; i < number_of_classes; i++ ){
FloatArray3Add( classes_in_columns, class_indices );
FloatArrayReset( buffer );
this = &classes_in_columns->get[ classes_in_columns -> length-1 ];
FloatArray2Reset( this ); 
FloatArray2FilterByClass( this , values_in_columns, class_indices, class_enum = i , buffer  ); 
}
}

void OutBar( char * text, int i ){
printf("\n--------------------------------\n");
printf("%s", text );
printf("%i", i );
printf("\n");
printf("--------------------------------\n");
}





*/

/*
* - CROSS MULTIPLY           O(n^2) // can i do a linked-path-through 
* - LAYERED-CROSS-MULTIPLY   O(2^n)
* - LOOK FOR PATTERNS IN POOR PERFORMERS FOR IDEAS

*      ** TRY TO CAPTURE THE RELATIONSHIPS, maybe using the following          
* - CROSS MULTIPLY LINKED PATH
*      (x1,x2)->(x2,x3)->(x3,x4)
* - ACCOUNT FOR PATH
*      find optimal path - i.e. a path that only a specific class has been shown to take
*      find optimal order of the optimal path - or the one that is least likely to diviate to different class
*          - i.e. col-1(x) -> col-3(y) // only occurs in class-2

*      
*/



/* ---------------------------------
* OPTIMIZE NUMBER Of CLASSIFIERS
* ---------------------------------
* 1. find the aveage-accuracy of each column in predicting the value
* 2. find the columns with the higest average-accuracy
* 3. use the columns with the greatest accuracy at a number that meets redundancy criteria
*/

// Converting into CNF or DNF is at the heart of the original NP Complete problem, satisfiability


/*
* Instead of making the the probability based on number of neighbors
* make it on the probability of spaces
* 
* extend the voting method to include other methods... try to increase number of methods to derive votes
* 
* create areas based on connecting areas of big poointsd
* 
* 
* 
*/