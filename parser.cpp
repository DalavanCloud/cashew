
#include "parser.h"

namespace cashew {

// common strings

IString TOPLEVEL("toplevel"),
        DEFUN("defun"),
        BLOCK("block"),
        STAT("stat"),
        ASSIGN("assign"),
        NAME("name"),
        VAR("var"),
        CONDITIONAL("conditional"),
        BINARY("binary"),
        RETURN("return"),
        IF("if"),
        WHILE("while"),
        DO("do"),
        FOR("for"),
        SEQ("seq"),
        SUB("sub"),
        CALL("call"),
        NUM("num"),
        LABEL("label"),
        BREAK("break"),
        CONTINUE("continue"),
        SWITCH("switch"),
        STRING("string"),
        INF("inf"),
        NaN("nan"),
        TEMP_RET0("tempRet0"),
        UNARY_PREFIX("unary-prefix"),
        UNARY_POSTFIX("unary-postfix"),
        MATH_FROUND("Math_fround"),
        SIMD_FLOAT32X4("SIMD_float32x4"),
        SIMD_INT32X4("SIMD_int32x4"),
        PLUS("+"),
        MINUS("-"),
        OR("|"),
        AND("&"),
        XOR("^"),
        L_NOT("!"),
        B_NOT("~"),
        LT("<"),
        GE(">="),
        LE("<="),
        GT(">"),
        EQ("=="),
        NE("!="),
        DIV("/"),
        MOD("%"),
        RSHIFT(">>"),
        LSHIFT("<<"),
        TRSHIFT(">>>"),
        TEMP_DOUBLE_PTR("tempDoublePtr"),
        HEAP8("HEAP8"),
        HEAP16("HEAP16"),
        HEAP32("HEAP32"),
        HEAPF32("HEAPF32"),
        HEAPU8("HEAPU8"),
        HEAPU16("HEAPU16"),
        HEAPU32("HEAPU32"),
        HEAPF64("HEAPF64"),
        F0("f0"),
        EMPTY(""),
        FUNCTION("function"),
        OPEN_PAREN("("),
        COMMA(","),
        SET("=");

StringSet keywords("var function if else do while for break continue return switch case default throw try catch finally true false null"),
          operators(". ! ~ - + * / % + - << >> >>> < <= > >= == != & ^ | ? = ,");

const char* OPERATOR_INITS = "+-*/%<>&^|~=!,";
int MAX_OPERATOR_SIZE = 3;

StringIntMap operatorPrec;

struct Init {
  Init() {
    // highest
    operatorPrec["."] = 0;
    operatorPrec["!"] = operatorPrec["~"] = operatorPrec["-"] = operatorPrec["+"] = 1;
    operatorPrec["*"] = operatorPrec["/"] = operatorPrec["%"] = 2;
    operatorPrec["+"] = operatorPrec["-"] = 3;
    operatorPrec["<<"] = operatorPrec[">>"] = operatorPrec[">>>"] = 4;
    operatorPrec["<"] = operatorPrec["<="] = operatorPrec[">="] = operatorPrec[">"] = 5;
    operatorPrec["=="] = operatorPrec["!="] = 6;
    operatorPrec["&"] = 7;
    operatorPrec["^"] = 8;
    operatorPrec["|"] = 9;
    operatorPrec["?"] = 10;
    operatorPrec["="] = 11;
    operatorPrec[","] = 12;
    // lowest
  }
};

Init init;

} // namespace cashew

