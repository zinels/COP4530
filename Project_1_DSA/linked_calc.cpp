/* 
Project 1
Name: 
UID: 
Description: 
*/

#include "linked_calc.hpp"

// Default constructor definition
template <typename T>
LinkedCalc<T>::LinkedCalc() : head(nullptr) {}

// Destructor to deallocate memory
template <typename T>
LinkedCalc<T>::~LinkedCalc() {
    while (head){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

}

// Function to insert a new node at the end of the linked list
template <typename T>
void LinkedCalc<T>::insert(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Helper function to determine if a character is a digit
template <typename T>
bool LinkedCalc<T>::isDigit(const T& c) {
    return (c >= '0' && c <= '9') ;
}

template <typename T>
bool LinkedCalc<T>::validateExpression() {
    if (head == nullptr || !isDigit(head->data)){
        return false;
    }

    bool lastSeenDigit = false;
    bool lastSeenOperator = false;
    bool lastSeenDecimal = false;

    Node<T>* current = head;

    while (current){
        T thisNodeData = current->data;

        if(isDigit(thisNodeData)){
            lastSeenDigit = true;
            lastSeenDecimal = false;
            lastSeenOperator = false;
        } else if (thisNodeData == '.'){
            if (lastSeenDecimal || lastSeenOperator){
                return false; // invalid expression 
            }
            lastSeenDecimal = true;
            lastSeenDigit = false;
            lastSeenOperator = false;
        } else if (thisNodeData == '*' || thisNodeData == '/' || thisNodeData == '+' || thisNodeData == '-'){
            if (lastSeenDecimal || lastSeenOperator){  
                return false; // invalid expression
            }
            lastSeenOperator = true;
            lastSeenDigit = false;
            lastSeenDecimal = false;
        } else if (lastSeenOperator && !isDigit(thisNodeData)) {
            return false;  // invalid expression
        }

        current = current->next;
    }

    return lastSeenDigit; // expression must end with a digit
    
}


// Function to evaluate the expression represented by the linked list
template <typename T>
float LinkedCalc<T>::evaluateExpression() {
    if (!validateExpression()){
        throw std::invalid_argument("Invalid expression");
    }

    // use two dynamic arrays to store numbers and operators separately
    std::vector<float> numbers;
    std::vector<char> operators;

    Node<T>* current = head;

    // traverse through the array and add each number and operator to their respective vector array
    while(current){
        if (isDigit(current->data) || current->data == '.'){ 
            float this_num = convertToFloat(current);
            numbers.push_back(this_num);
        } else{ // if it is an operator
            operators.push_back(current->data);
            current = current->next;
        }
    }

    // Evaluation first pass: handle multiplication and division
    std::vector<float> newNumbers;
    std::vector<char> newOperators;
    
    newNumbers.push_back(numbers[0]);
    int numIndex = 1;
    for (size_t i = 0; i < operators.size(); i++) {
        char this_operator = operators[i];
        if (this_operator == '*' || this_operator == '/') { 
            float left = newNumbers.back(); 
            float right = numbers[numIndex++];
            if (this_operator == '*'){
                float intermediate = left * right;
            } else{
                float intermediate = left / right;
            }
            newNumbers.back() = intermediate;
        } else {
            newOperators.push_back(this_operator);
            newNumbers.push_back(numbers[numIndex++]);
        }
    }
    
    // Evaluation first pass: handle addition and subtraction
    float result = newNumbers[0];
    for (size_t i = 0; i < newOperators.size(); ++i) {
        char this_operator = newOperators[i];
        if (this_operator == '+')
            result += newNumbers[i + 1];
        else if (this_operator == '-')
            result -= newNumbers[i + 1];
    }
    
    return result;
}

// Helper function to convert
template <typename T>
float LinkedCalc<T>::convertToFloat(Node<T>*& current){
    std::string numberString;
    bool hasDecimal = false;

    while (current && (isDigit(current->data) || current->data == '.')){
        numberString.push_back(current->data);
        current = current->next;
    }

    try{
        return std::stof(numberString);
    } catch(const std::exception&){
        throw std::runtime_error("Error. Cannot convert to float");
    }
}