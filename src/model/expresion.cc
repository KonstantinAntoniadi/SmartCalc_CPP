#include "Expresion.h"

// int getPostfix(const char *infix, char *postfix) {
//   int good_to_go = 1;
//   int index = 0;
//   int infix_len = (int)strlen(infix);
//   char in = {0};
//   char add = {0};
//   operation *head = NULL;
//   char prev = {0};

//   for (int i = 0; i < infix_len && good_to_go; i++) {
//     in = infix[i];
//     if (in == 'x') {
//       postfix[index++] = in;
//       postfix[index++] = ' ';
//     } else if (in == '(') {
//       good_to_go = pushOp(&head, in);
//     } else if (isFunc(in)) {
//       good_to_go = validateFunc(infix, &i, &add);
//       if (good_to_go) good_to_go = pushOp(&head, add);
//     } else if (isOperator(in)) {
//       good_to_go = validateOperator(infix, &i, head, &add, prev);
//       if (good_to_go) good_to_go = processOperator(&head, postfix, &index,
//       add);
//     } else if (in == ')') {
//       good_to_go = processBracket(&head, postfix, &index);
//     } else if (isdigit(in)) {
//       good_to_go = addDigit(infix, &i, postfix, &index);
//     } else if (in != ' ') {
//       good_to_go = 0;
//     }

//     prev = in;
//   }
//   if (good_to_go) good_to_go = processRemains(&head, postfix, &index);
//   if (good_to_go) good_to_go = validateRPN(postfix);

//   return good_to_go;
// }

namespace s21 {
void Expresion::Calculate() {
  GetPostfix();
  // std::cout <<
}

void Expresion::GetPostfix() {
  // std::cout << infix_ << std::endl;
  // infix_ +
  // cur_pos_ = infix_.begin();
  for (cur_pos_ = infix_.begin(); cur_pos_ != infix_.end() && good_to_go_;
       cur_pos_++) {
    if (*cur_pos_ == 'x') {
      postfix_.push_back(*cur_pos_);
      postfix_.push_back(' ');
    } else if (*cur_pos_ == ')') {  // возможно тоже заменит на enum
      operations_.push(BRACKET);
    } else if (IsValidFunc(*cur_pos_)) {
      good_to_go_ = IsValidFunc();
      if (good_to_go_) good_to_go_ =
    }
  }
}

bool Expresion::IsValidFunc(const char check) {
  // перепиши и используй итератор
  std::string funcs = "cstal";
  return (funcs.find(check) != std::string::npos);
}

bool Expresion::IsValidFunc() {
  if (*cur_pos_ == 'c' && *(cur_pos_ + 1) == 'o' && *(cur_pos_ + 2) == 's') {
    op_ = COS;
    cur_pos_ += 2;
  } else if (*cur_pos_ == 's' && *(cur_pos_ + 1) == 'i' &&
             *(cur_pos_ + 2) == 'n') {
    op_ = SIN;
    cur_pos_ += 2;
  } else if (*cur_pos_ == 't' && *(cur_pos_ + 1) == 'a' &&
             *(cur_pos_ + 2) == 'n') {
    op_ = TAN;
    cur_pos_ += 2;
  } else if (*cur_pos_ == 'a' && *(cur_pos_ + 1) == 'c' &&
             *(cur_pos_ + 2) == 'o' && *(cur_pos_ + 3) == 's') {
    op_ = ACOS;
    cur_pos_ += 3;
  } else if (*cur_pos_ == 'a' && *(cur_pos_ + 1) == 's' &&
             *(cur_pos_ + 2) == 'i' && *(cur_pos_ + 3) == 'n') {
    op_ = ASIN;
    cur_pos_ += 3;
  } else if (*cur_pos_ == 'a' && *(cur_pos_ + 1) == 't' &&
             *(cur_pos_ + 2) == 'a' && *(cur_pos_ + 3) == 'n') {
    op_ = ATAN;
    cur_pos_ += 3;
  } else if (*cur_pos_ == 's' && *(cur_pos_ + 1) == 'q' &&
             *(cur_pos_ + 2) == 'r' && *(cur_pos_ + 3) == 't') {
    op_ = ATAN;
    cur_pos_ += 3;
  } else if (*cur_pos_ == 'l' && *(cur_pos_ + 1) == 'n') {
    op_ = LN;
    cur_pos_ += 1;
  } else if (*cur_pos_ == 'l' && *(cur_pos_ + 1) == 'o' &&
             *(cur_pos_ + 2) == 'g') {
    op_ = LOG;
    cur_pos_ += 2;
  } else {
    return false;
  }

  return true;
}

};  // namespace s21