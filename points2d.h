// --> Weichao Lin
// Few comments describing the class Points2D

#ifndef CSCI335_HOMEWORK2_POINTS2D_H_
#define CSCI335_HOMEWORK2_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
// Place comments that provide a brief explanation of this class,
// and its sample usage.
template<typename Object>
class Points2D {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation for it.

  // Zero-parameter constructor. 
  // Set size and to 0, and pointer sequence_ to nullptr because we will use it later. 
  Points2D(){
  sequence_=nullptr;
  //set sequence pointer to be null because it will be used later
  size_=0;
  //initialize size to be 0
  }

  // Copy-constructor.
  //using the exsing object to initialize the other object.
  Points2D(const Points2D &rhs) {
  if(rhs.size()==0){
  //if the size equal 0
    size_=0;
  //size will set to be zero
    sequence_=nullptr;
  //sequence pointer will be null
  }else{
    size_=rhs.size();
  //on the other hand, the object with size will replace size
    sequence_=new std::array<Object,2>[size_];
  //the new 2d size will replace the pointer
    for(int i=0;i<size_;i++){
      sequence_[i]=rhs.sequence_[i];
    //the object with sequence pointer will replace sequence one by one if it is less than size
    }
  }
  };

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points2D copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  //the value of the object copy to the other
  Points2D& operator=(const Points2D &rhs){
    Points2D copy=rhs;
  //make rhs to be a copy that will use for swap late
    std::swap(*this,copy);
  //swap the address and copy
    return *this;
  //get the result of the address
  }

  // Move-constructor. 
  //right value match const &type, so if it doesn't have move constructor, it will copy constructor
  Points2D(Points2D &&rhs){
    sequence_=std::move(rhs.sequence_);
    //make sequence pointer to be move function 
    size_=std::move(rhs.size_);
    //make size to be move function
    rhs.sequence_=nullptr;
    //make rhs with sequence pointer to be null
    rhs.size_=0;
    //initilize rhs with size 
  }

/*
  Points2D(Points2D &&rhs){
    sequence_=std::move(rhs.sequence_);
    size_=std::move(rhs.size_);
    rhs.sequence_=nullptr;
    rhs.size_=0;
  }
*/

  // Move-assignment.
  // Just use std::swap() for all variables.
  //use the right value reference as assignment and return the object reference
  Points2D& operator=(Points2D &&rhs){
    if(this!=&rhs){
    //if the address is not equal to the rhs
      std::swap(size_,rhs.size_);
    //swap the size with the object with size
      std::swap(sequence_,rhs.sequence_);
    //swap the sequence pointer with the object with sequence pointer
    }
    return *this;
    //return to his own address
  };
//destructor
//delete the list and make pointer to be null
  ~Points2D(){
    delete[] sequence_;
    //delete the sequence pointer
    sequence_=nullptr;
    //make sequence to be null
  };

  // End of big-five.

  // One parameter constructor.
  //initize the size and pointer to be one
  Points2D(const std::array<Object, 2>& item) {
    // Provide code.
    size_=item.size()/2;
    //make the size with the object with size function divide by 2 because will not see that {0,0}
    sequence_=new std::array<Object,2>{item};
    //make the sequence pointer to be the 2d array
  }
 
  // Read a chain from standard input and make it can be visulized.
  void ReadPoints2D() {
    // Part of code included (without error checking).
    std::string input_line;
    //initilize the string named iput_line
    std::getline(std::cin, input_line); 
    //receive the input-line string
    std::stringstream input_stream(input_line);
    //replace the data using stringstream function
    if (input_line.empty()) return;
    // Read size of sequence (an integer).
    int size_of_sequence;
    //initilize the int name size_of sequence
    input_stream >> size_of_sequence;
    // Allocate space for sequence.
    // Add code here.
    size_=size_of_sequence;
    //make the size_of sequence to be size
    sequence_=new std::array<Object,2>[size_of_sequence];
    //make the 2d array to be sequence
    Object token;
    //initilize the new object name token
    for (int i = 0 ;input_stream >> token; ++i) {
      // Read coordinates.
      // Fill sequence_ here.
      sequence_[i][0]=token;
      //make the object to be two size like [a,b]
      input_stream>>token;
      //input the stream to be token object
      sequence_[i][1]=token;
      //make the object to be two size like [a,b]
    }
    
  }

  size_t size() const {
    // Code missing.
    return size_;
    //return size
  }
///////////////////////////////////////////////////////////////////
  // @location: an index to a location in the given sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
//if it has problem,it will throw out the mistak,otherwise, it will return
  const std::array<Object, 2>& operator[](size_t location) const { 
    // Code missing.
    if((location<0)or( location>=size_)){
    //if locaiton less than 0 or location large than or equal to size
      throw "location out of range\n";
    //print out the result string
      abort();
    //stop working
    }
    else
    //else
    return sequence_[location];
    //return the sequence pointer with location
  }
  
 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
   // Code missing.
   Points2D<double> re;
   //the sequence of result
   int c1s=c1.size();
   //use ec1s to replace c1.size()
   int c2s=c2.size();
   //use c2s to replace c2.size()

   if(c1s==c2s){
  //if c1s and c2s are equal
     re.size_ = c2s;
  //c2s will become the object with size
     re.sequence_ = new std::array<Object, 2>[re.size_];
  //the 2d array will become sequence with object

     size_t i=0;
  //make the i variable to be 0
     while(i<re.size_){
  //when i less than the object with size
       re.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
  //plus them together
       re.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
  //plus them together
       i++;
  //i to be large
     }
    }
    else if (c1s > c2s) {
  //if c1s large than c2s
      re.size_= c1s;
  //c1s become the object with size
      re.sequence_ = new std::array<Object, 2>[re.size_];
  //2d array will become the object with sequence
      for (size_t i = 0; i < c2s; i++) {
      //if i less than c2s, it will do this action
        re.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
      //plus them together
        re.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
      //plus them together
      }
      
      // appending the result with the remaining part of the larger sequence (c1).
      size_t i=c2s;
      //make c2s to be i variable
      while(i<re.size_){
      //when i less than size with objec
        re.sequence_[i][0] = c1.sequence_[i][0];
      //the size in array are the same
        re.sequence_[i][1] = c1.sequence_[i][1];
      //the size in array are the same
        i++;
      //i become large
      }

    } else {
      //the other result
        re.size_= c2s;
        //c2s become the size with object
        re.sequence_= new std::array<Object, 2>[re.size_];
        //2d array become the sequence pointer 
        for (size_t i = 0; i < c1s; i++) {
        //when i less than c1s, it will do this action
          re.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
        //plus them together
          re.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
        //plus them together
        }
        
        
        size_t i=c1s;
        //c1s to be i
        while(i<re.size_){
        //when i less than size with object, it will do this action
          re.sequence_[i][0] = c2.sequence_[i][0];
        //2d array will be the same
          re.sequence_[i][1] = c2.sequence_[i][1];
        //2d array will be the same
          i++;
        //i become large
        }

      }
    return re;
    //return the object
  }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points2d) {
   // Code missing.
    if ((some_points2d.sequence_ != nullptr) and (some_points2d.size_ == 1)) {
    //if the sequence with pointer are not null and size with object are 1, it does this action
      out << "(" << some_points2d.sequence_->at(0) << ", " << some_points2d.sequence_->at(1) << ")";
    //it output the result(a,b)
    }
    if ((some_points2d.sequence_ != nullptr) and (some_points2d.size_ > 1)) {
    //if the sequnce with pointer are not null and size with object large than 1
      size_t i=0;
    //variable become 0
      while(i<some_points2d.size_){
      //when i less than size with object
        out << "(" << some_points2d.sequence_[i][0] << ", " << some_points2d.sequence_[i][1] << ")" << " ";
      //it output the result(a,b)
      i++;
      //i become large
      }

    }
    if (some_points2d.sequence_ == nullptr) {
    //if sequence with object are null
      out << "()";
    //it only output the ()
    }
    out<<"\n";
    //it output the new line
    return out;
    //it will come beck to the object
 }
 
 private:
  // Sequence of points. 
  std::array<Object, 2> *sequence_;
  // Size of the sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK2_POINTS2D_H_
