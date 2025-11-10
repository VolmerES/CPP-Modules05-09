#!/bin/bash

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}================================${NC}"
echo -e "${BLUE}   RPN CALCULATOR - TESTS${NC}"
echo -e "${BLUE}================================${NC}\n"

# Función para ejecutar test
run_test() {
    local test_name="$1"
    local expected="$2"
    shift 2
    local cmd="$@"
    
    echo -e "${YELLOW}Test: ${test_name}${NC}"
    echo -e "Command: ${cmd}"
    
    result=$(eval "$cmd" 2>&1)
    exit_code=$?
    
    if [ "$exit_code" -eq 0 ] && [ "$result" == "$expected" ]; then
        echo -e "${GREEN}✓ PASS${NC} - Output: $result\n"
        return 0
    elif [ "$exit_code" -ne 0 ] && [ "$expected" == "Error" ]; then
        echo -e "${GREEN}✓ PASS${NC} - Error detected correctly\n"
        return 0
    else
        echo -e "${RED}✗ FAIL${NC} - Expected: '$expected', Got: '$result' (exit: $exit_code)\n"
        return 1
    fi
}

passed=0
failed=0
failed_tests=()

# ========== TESTS VÁLIDOS ==========
echo -e "${BLUE}======= VALID EXPRESSIONS =======${NC}\n"

run_test "Basic addition" "3" "./RPN \"1 2 +\"" && ((passed++)) || { ((failed++)); failed_tests+=("Basic addition"); }
run_test "Basic subtraction" "2" "./RPN \"5 3 -\"" && ((passed++)) || { ((failed++)); failed_tests+=("Basic subtraction"); }
run_test "Basic multiplication" "72" "./RPN \"9 8 *\"" && ((passed++)) || { ((failed++)); failed_tests+=("Basic multiplication"); }
run_test "Basic division" "2" "./RPN \"4 2 /\"" && ((passed++)) || { ((failed++)); failed_tests+=("Basic division"); }

run_test "Subject example 1" "42" "./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" && ((passed++)) || { ((failed++)); failed_tests+=("Subject example 1"); }
run_test "Subject example 2" "42" "./RPN \"7 7 * 7 -\"" && ((passed++)) || { ((failed++)); failed_tests+=("Subject example 2"); }
run_test "Subject example 3" "0" "./RPN \"1 2 * 2 / 2 * 2 4 - +\"" && ((passed++)) || { ((failed++)); failed_tests+=("Subject example 3"); }

run_test "Single number" "5" "./RPN \"5\"" && ((passed++)) || { ((failed++)); failed_tests+=("Single number"); }
run_test "Zero result" "0" "./RPN \"5 5 -\"" && ((passed++)) || { ((failed++)); failed_tests+=("Zero result"); }
run_test "Complex expression" "14" "./RPN \"5 1 2 + 4 * + 3 -\"" && ((passed++)) || { ((failed++)); failed_tests+=("Complex expression"); }

run_test "Multiple spaces" "3" "./RPN \"1  2   +\"" && ((passed++)) || { ((failed++)); failed_tests+=("Multiple spaces"); }
run_test "Spaces at edges" "3" "./RPN \" 1 2 + \"" && ((passed++)) || { ((failed++)); failed_tests+=("Spaces at edges"); }

# ========== TESTS DE ERROR ==========
echo -e "${BLUE}======= ERROR CASES =======${NC}\n"

run_test "No arguments" "Error" "./RPN" && ((passed++)) || { ((failed++)); failed_tests+=("No arguments"); }
run_test "Empty string" "Error" "./RPN \"\"" && ((passed++)) || { ((failed++)); failed_tests+=("Empty string"); }
run_test "Only spaces" "Error" "./RPN \"   \"" && ((passed++)) || { ((failed++)); failed_tests+=("Only spaces"); }

run_test "Insufficient operands" "Error" "./RPN \"1 +\"" && ((passed++)) || { ((failed++)); failed_tests+=("Insufficient operands"); }
run_test "Only operator" "Error" "./RPN \"+\"" && ((passed++)) || { ((failed++)); failed_tests+=("Only operator"); }
run_test "Operator first" "Error" "./RPN \"* 1 2\"" && ((passed++)) || { ((failed++)); failed_tests+=("Operator first"); }

run_test "Too many numbers" "Error" "./RPN \"1 2\"" && ((passed++)) || { ((failed++)); failed_tests+=("Too many numbers"); }
run_test "Multiple results" "Error" "./RPN \"1 2 3 +\"" && ((passed++)) || { ((failed++)); failed_tests+=("Multiple results"); }

run_test "Division by zero" "Error" "./RPN \"1 0 /\"" && ((passed++)) || { ((failed++)); failed_tests+=("Division by zero"); }
run_test "Division by zero 2" "Error" "./RPN \"5 0 /\"" && ((passed++)) || { ((failed++)); failed_tests+=("Division by zero 2"); }

run_test "Invalid character" "Error" "./RPN \"1 2 a\"" && ((passed++)) || { ((failed++)); failed_tests+=("Invalid character"); }
run_test "Invalid operator" "Error" "./RPN \"1 2 &\"" && ((passed++)) || { ((failed++)); failed_tests+=("Invalid operator"); }
run_test "Parentheses" "Error" "./RPN \"(1 + 1)\"" && ((passed++)) || { ((failed++)); failed_tests+=("Parentheses"); }
run_test "Decimal point" "Error" "./RPN \"1.5 2 +\"" && ((passed++)) || { ((failed++)); failed_tests+=("Decimal point"); }
run_test "Multi-digit number" "Error" "./RPN \"10 2 +\"" && ((passed++)) || { ((failed++)); failed_tests+=("Multi-digit number"); }
run_test "Negative number" "Error" "./RPN \"1 -2 +\"" && ((passed++)) || { ((failed++)); failed_tests+=("Negative number"); }

# ========== RESUMEN ==========
echo -e "${BLUE}================================${NC}"
echo -e "${BLUE}         SUMMARY${NC}"
echo -e "${BLUE}================================${NC}"
echo -e "${GREEN}Passed: ${passed}${NC}"
echo -e "${RED}Failed: ${failed}${NC}"
echo -e "${BLUE}Total:  $((passed + failed))${NC}"

if [ $failed -gt 0 ]; then
    echo -e "\n${RED}Failed tests:${NC}"
    for test in "${failed_tests[@]}"; do
        echo -e "${RED}  - $test${NC}"
    done
fi

if [ $failed -eq 0 ]; then
    echo -e "\n${GREEN}🎉 ALL TESTS PASSED! 🎉${NC}\n"
    exit 0
else
    echo -e "\n${RED}❌ SOME TESTS FAILED ❌${NC}\n"
    exit 1
fi