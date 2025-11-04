void infixTopostfix(string infix, string &postfix){
    if(infix == "") {
        cout<<"Empty expression";
        return;
    }
    Stack s;

    for(int i = 0; i < infix.size(); i++){
        char c = infix[i];

        if(isOperand(c)){
            postfix.push_back(c);
        }
        else if(c == '('){
            s.push(c);
        }
        else if(c == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                postfix.push_back(s.pop());
            }
            s.pop();
        }
        else if(isOperator(c)){
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(c)){
                postfix.push_back(s.pop());
            }
            s.push(c);
        }
    }

    while(!s.isEmpty()){
        postfix.push_back(s.pop());
    }
}

void infixToprefix(string infix){
    reverse(infix);
    for(int i = 0; i < infix.size(); i++){
        if(infix[i] == '(') infix[i] = ')';
        else if(infix[i] == ')') infix[i] = '(';
    }

    string postfix;
    infixTopostfix(infix, postfix);
    reverse(postfix);

    cout << "Prefix: " << postfix << endl;
}

int main(){
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    infixToprefix(infix);

    return 0;
}
