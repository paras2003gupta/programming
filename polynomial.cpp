#include <iostream>
using namespace std;
class poly{
    public:
    int expo;
    int coff;
    poly *next;

   
    poly(int expo,int coff){
        this->expo = expo;
        this->coff = coff;
        this->next = NULL;
    }
    

};
class polynomial{
    private:
    poly* head;
    public:
    polynomial(){
        this->head=NULL;

    }
    
    // insert a term into a polynomial
    void insertpoly(int exponent,int cofficient){
        // make a item that has to be inserted in a polynomial.
        poly*newterm = new poly(exponent,cofficient);
        poly*head = newterm;

        if(head==NULL){
            head = newterm;
            return;
        }
        poly *curr = head;

        // finding right position to insert the newterm
        while(curr->next!=NULL&&curr->next->expo>exponent){
            curr = curr->next;
        }
        newterm->next = curr->next;
        curr->next = newterm;





    }
    void addpolynomial(poly*head1 , poly* head2){
        

    }



};
int main(){

}