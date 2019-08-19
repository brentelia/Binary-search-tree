#include "../include/BSTree.hpp"
#include"../include/FileIO.hpp"
#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#undef CATCH_CONFIG_MAIN
#include <iomanip>
#include <iostream>
#include<string>
#include <algorithm>


TEST_CASE("File Reader OK","[ReadFile]"){

    std::string fileIN="../data/input.txt";
    auto file=fileIO::readFile(fileIN);
    auto vals=fileIO::stringToVector(file,'\n');
    std::vector<int> values=std::vector<int>();
    for(auto i:vals){
        values.push_back(stoi(i));
    }
    std::vector<int> testVector={8,16,2,7,0,66,-3};
    REQUIRE (values==testVector);
}

TEST_CASE("Integer Tree OK", "[IntBTree]") {
    std::vector<int> values={-2,48,5,127};
    std::string sort="unsorted";
    auto tree1=new BSTree<int>(values,sort);
    auto vect2=std::vector<int>();
    tree1->treeToVector(vect2); 
    REQUIRE(values!=vect2);
    
    auto tree=new BSTree<int>(values);
    std::sort(values.begin(),values.end());
    REQUIRE(values==vect2);
    delete tree1;
    vect2.clear();
    tree->treeToVector(vect2);
    REQUIRE(values==vect2);
    

    auto tree2=*tree + *tree;
    REQUIRE(*tree==tree2);

    REQUIRE(tree2.treeNumbers()==2);
    delete tree;
    REQUIRE(tree2.treeNumbers()==1);

    std::vector<int> val1={1,2,3,4};
    std::vector<int> val2={5,6,7,8};
    auto T1=new BSTree<int>(val1);
    auto T2=new BSTree<int>(val2);
    auto T3= *T1+*T2;
    std::vector<int> val3= std::vector<int>();
    int x= 5;
    T3.remove(x);
    T3.treeToVector(val3);
    
    std::vector<int> testVector={1,2,3,4,6,7,8};
    REQUIRE(val3==testVector);
    
    val3.clear();
    x=10;
    T3.insert(x);
    T3.treeToVector(val3);
    testVector={1,2,3,4,6,7,8,10};
    REQUIRE(testVector==val3);
    T3.print();
    delete T2;
    delete T1;
}

TEST_CASE("String Tree OK", "[StringBTree]") {
    std::vector<std::string> values={"albero","delfino","cocco","banana"};
    std::string sort="unsorted";
    auto tree1=new BSTree<std::string>(values,sort);
    auto vect2=std::vector<std::string>();
    tree1->treeToVector(vect2); 
    REQUIRE(values!=vect2);
    
    auto tree=new BSTree<std::string>(values);
    std::sort(values.begin(),values.end());
    REQUIRE(values==vect2);
   
    delete tree1;
    vect2.clear();
    tree->treeToVector(vect2);
    REQUIRE(values==vect2);

    auto tree2=*tree + *tree;
    REQUIRE(*tree==tree2);

    REQUIRE(tree2.treeNumbers()==2);
    delete tree;
    REQUIRE(tree2.treeNumbers()==1);

    std::vector<std::string> val1={"camicia","campana","gatto","armadillo"};
    std::vector<std::string> val2={"televisore","piazza","sedia","albero"};
    auto T1=new BSTree<std::string>(val1);
    auto T2=new BSTree<std::string>(val2);
    auto T3= *T1+*T2;
    std::vector<std::string> val3= std::vector<std::string>();
    std::string x= "campana";
    T3.remove(x);
    T3.treeToVector(val3);
    
    std::vector<std::string> testVector={"albero","armadillo","camicia","gatto","piazza","sedia","televisore"};
    REQUIRE(val3==testVector);
    
    val3.clear();
    x="violino";
    T3.insert(x);
    T3.treeToVector(val3);
    testVector={"albero","armadillo","camicia","gatto","piazza","sedia","televisore","violino"};
    REQUIRE(testVector==val3);
    T3.print();
    delete T2;
    delete T1;
}
