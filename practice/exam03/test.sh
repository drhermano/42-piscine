#!/bin/bash
# ============================================================
#  42 School – Exam Exercise Test Suite
#  Usage: place this file in the same dir as your .c files
#         then run: bash test.sh
# ============================================================

RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[1;33m'
BLUE='\033[0;34m'; BOLD='\033[1m'; NC='\033[0m'

PASS=0; FAIL=0
TMP=$(mktemp -d)
trap "rm -rf $TMP" EXIT

# ── helpers ────────────────────────────────────────────────

check() {
    local desc="$1" expected="$2" actual="$3"
    if [ "$expected" = "$actual" ]; then
        printf "  ${GREEN}✓${NC} %s\n" "$desc"; ((PASS++))
    else
        printf "  ${RED}✗${NC} %s\n" "$desc"
        printf "    expected |%s|\n" "$(printf '%s' "$expected" | cat -v)"
        printf "    got      |%s|\n" "$(printf '%s' "$actual"   | cat -v)"
        ((FAIL++))
    fi
}

section()      { printf "\n${BLUE}${BOLD}══ %s ══${NC}\n" "$1"; }
skip_msg()     { printf "  ${YELLOW}⚠  %s.c not found – skipping${NC}\n" "$1"; }
bad_compile()  { printf "  ${RED}✗  compilation failed (see $TMP/err_%s)${NC}\n" "$1"; ((FAIL++)); }

compile_prog() {          # compile_prog <name>
    local name="$1"
    gcc -Wall -o "$TMP/$name" "${name}.c" 2>"$TMP/err_$name"
}

make_func_test() {        # make_func_test <name> <c-code-for-main>
    local name="$1" code="$2"
    printf '%s\n' "$code" > "$TMP/main_$name.c"
    gcc -Wall -o "$TMP/test_$name" "$TMP/main_$name.c" "${name}.c" 2>"$TMP/err_$name"
}

# ================================================================
#  PROGRAMS  (student writes main)
# ================================================================

# ── aff_last_param ──────────────────────────────────────────
section "aff_last_param"
if   [ ! -f aff_last_param.c ]; then skip_msg aff_last_param
elif ! compile_prog aff_last_param; then bad_compile aff_last_param
else
    check "multiple args"     "chats"           "$($TMP/aff_last_param zaz mange des chats)"
    check "single arg"        "j'aime le savon" "$($TMP/aff_last_param "j'aime le savon")"
    check "no args → newline" ""                "$($TMP/aff_last_param)"
fi

# ── aff_z ───────────────────────────────────────────────────
section "aff_z"
if   [ ! -f aff_z.c ]; then skip_msg aff_z
elif ! compile_prog aff_z; then bad_compile aff_z
else
    check '"abc" (no z)'              "z" "$($TMP/aff_z "abc")"
    check '"dubO a POIL" (no z)'      "z" "$($TMP/aff_z "dubO a POIL")"
    check '"zaz sent le poney" (z=z)' "z" "$($TMP/aff_z "zaz sent le poney")"
    check "no args"                   "z" "$($TMP/aff_z)"
fi

# ── expand_str ──────────────────────────────────────────────
section "expand_str"
if   [ ! -f expand_str.c ]; then skip_msg expand_str
elif ! compile_prog expand_str; then bad_compile expand_str
else
    check "already spaced" \
        "vous   voyez   c'est   facile   d'afficher   la   meme   chose" \
        "$($TMP/expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose")"
    check "trim + collapse" \
        "seulement   la   c'est   plus   dur" \
        "$($TMP/expand_str " seulement          la c'est      plus dur ")"
    check "2 args → newline" "" "$($TMP/expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?")"
    check "empty string"     "" "$($TMP/expand_str "")"
fi

# ── fizzbuzz ────────────────────────────────────────────────
section "fizzbuzz"
if   [ ! -f fizzbuzz.c ]; then skip_msg fizzbuzz
elif ! compile_prog fizzbuzz; then bad_compile fizzbuzz
else
    FB=$($TMP/fizzbuzz)
    check "line 1   = 1"         "1"        "$(sed -n '1p'   <<< "$FB")"
    check "line 2   = 2"         "2"        "$(sed -n '2p'   <<< "$FB")"
    check "line 3   = fizz"      "fizz"     "$(sed -n '3p'   <<< "$FB")"
    check "line 5   = buzz"      "buzz"     "$(sed -n '5p'   <<< "$FB")"
    check "line 6   = fizz"      "fizz"     "$(sed -n '6p'   <<< "$FB")"
    check "line 10  = buzz"      "buzz"     "$(sed -n '10p'  <<< "$FB")"
    check "line 15  = fizzbuzz"  "fizzbuzz" "$(sed -n '15p'  <<< "$FB")"
    check "line 30  = fizzbuzz"  "fizzbuzz" "$(sed -n '30p'  <<< "$FB")"
    check "line 99  = fizz"      "fizz"     "$(sed -n '99p'  <<< "$FB")"
    check "line 100 = buzz"      "buzz"     "$(sed -n '100p' <<< "$FB")"
    check "exactly 100 lines"    "100"      "$(wc -l <<< "$FB" | tr -d ' \t')"
fi

# ── inter ───────────────────────────────────────────────────
section "inter"
if   [ ! -f inter.c ]; then skip_msg inter
elif ! compile_prog inter; then bad_compile inter
else
    check "example 1" "padinto" "$($TMP/inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj")"
    check "example 2" "df6ewg4" "$($TMP/inter "ddf6vewg64f" "gtwthgdwthdwfteewhrtag6h4ffdhsd")"
    check "example 3" "rien"    "$($TMP/inter "rien" "cette phrase ne cache rien")"
    check "no args"   ""        "$($TMP/inter)"
fi

# ── repeat_alpha ────────────────────────────────────────────
section "repeat_alpha"
if   [ ! -f repeat_alpha.c ]; then skip_msg repeat_alpha
elif ! compile_prog repeat_alpha; then bad_compile repeat_alpha
else
    check '"abc"' \
        "abbccc" \
        "$($TMP/repeat_alpha "abc")"
    check '"Alex."' \
        "Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx." \
        "$($TMP/repeat_alpha "Alex.")"
    check '"abacadaba 42!"' \
        "abbacccaddddabba 42!" \
        "$($TMP/repeat_alpha "abacadaba 42!")"
    check "no args"      "" "$($TMP/repeat_alpha)"
    check "empty string" "" "$($TMP/repeat_alpha "")"
fi

# ── rev_print ───────────────────────────────────────────────
section "rev_print"
if   [ ! -f rev_print.c ]; then skip_msg rev_print
elif ! compile_prog rev_print; then bad_compile rev_print
else
    check '"zaz"'         "zaz"         "$($TMP/rev_print "zaz")"
    check '"dub0 a POIL"' "LIOP a 0bud" "$($TMP/rev_print "dub0 a POIL")"
    check "no args"       ""            "$($TMP/rev_print)"
fi

# ── rstr_capitalizer ────────────────────────────────────────
section "rstr_capitalizer"
if   [ ! -f rstr_capitalizer.c ]; then skip_msg rstr_capitalizer
elif ! compile_prog rstr_capitalizer; then bad_compile rstr_capitalizer
else
    check "no args" "" "$($TMP/rstr_capitalizer)"
    check "single arg" \
        "premieR petiT tesT" \
        "$($TMP/rstr_capitalizer "Premier PETIT TesT")"
    RST=$($TMP/rstr_capitalizer \
        "DeuxiEmE tEST uN PEU moinS  facile" \
        "   attention C'EST pas dur QUAND mEmE" \
        "ALLer UN DeRNier 0123456789pour LA rouTE    E ")
    check "multi-arg line 1" \
        "deuxiemE tesT uN peU moinS  facilE" \
        "$(sed -n '1p' <<< "$RST")"
    check "multi-arg line 2" \
        "   attentioN c'esT paS duR quanD memE" \
        "$(sed -n '2p' <<< "$RST")"
    check "multi-arg line 3" \
        "alleR uN dernieR 0123456789pouR lA routE    E " \
        "$(sed -n '3p' <<< "$RST")"
fi

# ── search_and_replace ──────────────────────────────────────
section "search_and_replace"
if   [ ! -f search_and_replace.c ]; then skip_msg search_and_replace
elif ! compile_prog search_and_replace; then bad_compile search_and_replace
else
    check "basic replace" \
        "Popoche est un sobre" \
        "$($TMP/search_and_replace "Papache est un sabre" "a" "o")"
    check "2nd arg multi-char → newline" \
        "" \
        "$($TMP/search_and_replace "zaz" "art" "zul")"
    check "char not in string" \
        "zaz" \
        "$($TMP/search_and_replace "zaz" "r" "u")"
    check "too many args → newline" \
        "" \
        "$($TMP/search_and_replace "jacob" "a" "b" "c" "e")"
    check "replace o→a" \
        "ZaZ eT David aiME le METal." \
        "$($TMP/search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a")"
    check "replace w→e" \
        "eNcOre Un ExEmPle Pas Facile a Ecrire " \
        "$($TMP/search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e")"
fi

# ── tab_mult ────────────────────────────────────────────────
section "tab_mult"
if   [ ! -f tab_mult.c ]; then skip_msg tab_mult
elif ! compile_prog tab_mult; then bad_compile tab_mult
else
    TM9=$($TMP/tab_mult 9)
    check "9 × line 1 = 1 x 9 = 9"   "1 x 9 = 9"    "$(sed -n '1p' <<< "$TM9")"
    check "9 × line 5 = 5 x 9 = 45"  "5 x 9 = 45"   "$(sed -n '5p' <<< "$TM9")"
    check "9 × line 9 = 9 x 9 = 81"  "9 x 9 = 81"   "$(sed -n '9p' <<< "$TM9")"
    TM19=$($TMP/tab_mult 19)
    check "19 × line 2 = 2 x 19 = 38"  "2 x 19 = 38"  "$(sed -n '2p' <<< "$TM19")"
    check "19 × line 9 = 9 x 19 = 171" "9 x 19 = 171" "$(sed -n '9p' <<< "$TM19")"
    check "no args → newline" "" "$($TMP/tab_mult)"
fi

# ── ulstr ───────────────────────────────────────────────────
section "ulstr"
if   [ ! -f ulstr.c ]; then skip_msg ulstr
elif ! compile_prog ulstr; then bad_compile ulstr
else
    check "example 1" \
        "l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION." \
        "$($TMP/ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification.")"
    check "example 2" \
        "s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  " \
        "$($TMP/ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  ")"
    check "no args" "" "$($TMP/ulstr)"
fi

# ── union ───────────────────────────────────────────────────
section "union"
if   [ ! -f union.c ]; then skip_msg union
elif ! compile_prog union; then bad_compile union
else
    check "example 1" "zpadintoqefwjy" "$($TMP/union "zpadinton" "paqefwtdjetyiytjneytjoeyjnejeyj")"
    check "example 2" "df6vewg4thras"  "$($TMP/union "ddf6vewg64f" "gtwthgdwthdwfteewhrtag6h4ffdhsd")"
    check "example 3" "rienct phas"    "$($TMP/union "rien" "cette phrase ne cache rien")"
    check "no args"   ""               "$($TMP/union)"
    check "one arg"   ""               "$($TMP/union "rien")"
fi

# ================================================================
#  FUNCTIONS  (student writes only the function body, no main)
# ================================================================

# ── ft_strlen ───────────────────────────────────────────────
section "ft_strlen"
if [ ! -f ft_strlen.c ]; then skip_msg ft_strlen
else
    make_func_test ft_strlen '
#include <stdio.h>
int ft_strlen(char *str);
int main(void) {
    printf("%d\n", ft_strlen("hello"));
    printf("%d\n", ft_strlen(""));
    printf("%d\n", ft_strlen("abc"));
    printf("%d\n", ft_strlen("42 school"));
    return 0;
}'
    if [ ! -f "$TMP/test_ft_strlen" ]; then bad_compile ft_strlen
    else
        SL=$($TMP/test_ft_strlen)
        check 'ft_strlen("hello") = 5'     "5" "$(sed -n '1p' <<< "$SL")"
        check 'ft_strlen("") = 0'          "0" "$(sed -n '2p' <<< "$SL")"
        check 'ft_strlen("abc") = 3'       "3" "$(sed -n '3p' <<< "$SL")"
        check 'ft_strlen("42 school") = 9' "9" "$(sed -n '4p' <<< "$SL")"
    fi
fi

# ── ft_strcpy ───────────────────────────────────────────────
section "ft_strcpy"
if [ ! -f ft_strcpy.c ]; then skip_msg ft_strcpy
else
    make_func_test ft_strcpy '
#include <stdio.h>
char *ft_strcpy(char *s1, char *s2);
int main(void) {
    char dst[64];
    char *ret = ft_strcpy(dst, "hello");
    printf("%s\n", dst);
    printf("%d\n", ret == dst);
    ft_strcpy(dst, "42 school");
    printf("%s\n", dst);
    ft_strcpy(dst, "");
    printf("|%s|\n", dst);
    return 0;
}'
    if [ ! -f "$TMP/test_ft_strcpy" ]; then bad_compile ft_strcpy
    else
        SC=$($TMP/test_ft_strcpy)
        check 'copies "hello" to dst'     "hello"    "$(sed -n '1p' <<< "$SC")"
        check 'returns dst pointer'       "1"        "$(sed -n '2p' <<< "$SC")"
        check 'copies "42 school"'        "42 school" "$(sed -n '3p' <<< "$SC")"
        check 'copies empty string'       "||"        "$(sed -n '4p' <<< "$SC")"
    fi
fi

# ── ft_strdup ───────────────────────────────────────────────
section "ft_strdup"
if [ ! -f ft_strdup.c ]; then skip_msg ft_strdup
else
    make_func_test ft_strdup '
#include <stdio.h>
#include <stdlib.h>
char *ft_strdup(char *src);
int main(void) {
    char *d;
    d = ft_strdup("hello");     printf("%s\n",   d); free(d);
    d = ft_strdup("");          printf("|%s|\n", d); free(d);
    d = ft_strdup("42 school"); printf("%s\n",   d); free(d);
    return 0;
}'
    if [ ! -f "$TMP/test_ft_strdup" ]; then bad_compile ft_strdup
    else
        SD=$($TMP/test_ft_strdup)
        check 'strdup("hello")'     "hello"     "$(sed -n '1p' <<< "$SD")"
        check 'strdup("")'          "||"         "$(sed -n '2p' <<< "$SD")"
        check 'strdup("42 school")' "42 school"  "$(sed -n '3p' <<< "$SD")"
    fi
fi

# ── ft_strrev ───────────────────────────────────────────────
section "ft_strrev"
if [ ! -f ft_strrev.c ]; then skip_msg ft_strrev
else
    make_func_test ft_strrev '
#include <stdio.h>
char *ft_strrev(char *str);
int main(void) {
    char s1[] = "hello";
    char s2[] = "abcde";
    char s3[] = "";
    char s4[] = "a";
    char *r = ft_strrev(s1);
    printf("%s\n", s1);
    printf("%d\n", r == s1);
    printf("%s\n", ft_strrev(s2));
    printf("|%s|\n", ft_strrev(s3));
    printf("%s\n", ft_strrev(s4));
    return 0;
}'
    if [ ! -f "$TMP/test_ft_strrev" ]; then bad_compile ft_strrev
    else
        SR=$($TMP/test_ft_strrev)
        check 'rev("hello") = "olleh"' "olleh" "$(sed -n '1p' <<< "$SR")"
        check 'returns same pointer'   "1"     "$(sed -n '2p' <<< "$SR")"
        check 'rev("abcde") = "edcba"' "edcba" "$(sed -n '3p' <<< "$SR")"
        check 'rev("") = ""'           "||"    "$(sed -n '4p' <<< "$SR")"
        check 'rev("a") = "a"'         "a"     "$(sed -n '5p' <<< "$SR")"
    fi
fi

# ── ft_atoi ─────────────────────────────────────────────────
section "ft_atoi"
if [ ! -f ft_atoi.c ]; then skip_msg ft_atoi
else
    make_func_test ft_atoi '
#include <stdio.h>
int ft_atoi(const char *str);
int main(void) {
    printf("%d\n", ft_atoi("42"));
    printf("%d\n", ft_atoi("-42"));
    printf("%d\n", ft_atoi("   +42"));
    printf("%d\n", ft_atoi("0"));
    printf("%d\n", ft_atoi("  -0042"));
    printf("%d\n", ft_atoi("2147483647"));
    printf("%d\n", ft_atoi("-2147483648"));
    printf("%d\n", ft_atoi("42abc"));
    printf("%d\n", ft_atoi(""));
    return 0;
}'
    if [ ! -f "$TMP/test_ft_atoi" ]; then bad_compile ft_atoi
    else
        AT=$($TMP/test_ft_atoi)
        check 'atoi("42")'           "42"          "$(sed -n '1p' <<< "$AT")"
        check 'atoi("-42")'          "-42"         "$(sed -n '2p' <<< "$AT")"
        check 'atoi("   +42")'       "42"          "$(sed -n '3p' <<< "$AT")"
        check 'atoi("0")'            "0"           "$(sed -n '4p' <<< "$AT")"
        check 'atoi("  -0042")'      "-42"         "$(sed -n '5p' <<< "$AT")"
        check 'atoi("2147483647")'   "2147483647"  "$(sed -n '6p' <<< "$AT")"
        check 'atoi("-2147483648")'  "-2147483648" "$(sed -n '7p' <<< "$AT")"
        check 'atoi("42abc")'        "42"          "$(sed -n '8p' <<< "$AT")"
        check 'atoi("")'             "0"           "$(sed -n '9p' <<< "$AT")"
    fi
fi

# ── ft_itoa ─────────────────────────────────────────────────
section "ft_itoa"
if [ ! -f ft_itoa.c ]; then skip_msg ft_itoa
else
    make_func_test ft_itoa '
#include <stdio.h>
#include <stdlib.h>
char *ft_itoa(int nbr);
int main(void) {
    char *s;
    s = ft_itoa(42);          printf("%s\n", s); free(s);
    s = ft_itoa(-42);         printf("%s\n", s); free(s);
    s = ft_itoa(0);           printf("%s\n", s); free(s);
    s = ft_itoa(2147483647);  printf("%s\n", s); free(s);
    s = ft_itoa(-2147483648); printf("%s\n", s); free(s);
    return 0;
}'
    if [ ! -f "$TMP/test_ft_itoa" ]; then bad_compile ft_itoa
    else
        IT=$($TMP/test_ft_itoa)
        check 'itoa(42)'           "42"          "$(sed -n '1p' <<< "$IT")"
        check 'itoa(-42)'          "-42"         "$(sed -n '2p' <<< "$IT")"
        check 'itoa(0)'            "0"           "$(sed -n '3p' <<< "$IT")"
        check 'itoa(INT_MAX)'      "2147483647"  "$(sed -n '4p' <<< "$IT")"
        check 'itoa(INT_MIN)'      "-2147483648" "$(sed -n '5p' <<< "$IT")"
    fi
fi

# ── ft_print_numbers ────────────────────────────────────────
section "ft_print_numbers"
if [ ! -f ft_print_numbers.c ]; then skip_msg ft_print_numbers
else
    make_func_test ft_print_numbers '
#include <stdio.h>
void ft_print_numbers(void);
int main(void) {
    ft_print_numbers();
    return 0;
}'
    if [ ! -f "$TMP/test_ft_print_numbers" ]; then bad_compile ft_print_numbers
    else
        check 'prints "0123456789"' "0123456789" "$($TMP/test_ft_print_numbers)"
    fi
fi

# ── ft_range ────────────────────────────────────────────────
section "ft_range"
if [ ! -f ft_range.c ]; then skip_msg ft_range
else
    make_func_test ft_range '
#include <stdio.h>
#include <stdlib.h>
int *ft_range(int start, int end);
static void print_range(int start, int end) {
    int *r = ft_range(start, end);
    int len = end >= start ? end - start + 1 : start - end + 1;
    for (int i = 0; i < len; i++)
        printf("%d%s", r[i], i < len - 1 ? " " : "\n");
    free(r);
}
int main(void) {
    print_range(1,  3);
    print_range(-1, 2);
    print_range(0,  0);
    print_range(0, -3);
    return 0;
}'
    if [ ! -f "$TMP/test_ft_range" ]; then bad_compile ft_range
    else
        RG=$($TMP/test_ft_range)
        check 'range(1, 3)   = 1 2 3'      "1 2 3"      "$(sed -n '1p' <<< "$RG")"
        check 'range(-1, 2)  = -1 0 1 2'   "-1 0 1 2"   "$(sed -n '2p' <<< "$RG")"
        check 'range(0, 0)   = 0'           "0"          "$(sed -n '3p' <<< "$RG")"
        check 'range(0, -3)  = 0 -1 -2 -3' "0 -1 -2 -3" "$(sed -n '4p' <<< "$RG")"
    fi
fi

# ── ft_split ────────────────────────────────────────────────
section "ft_split"
if [ ! -f ft_split.c ]; then skip_msg ft_split
else
    make_func_test ft_split '
#include <stdio.h>
#include <stdlib.h>
char **ft_split(char *str);
static void print_split(char *str) {
    char **r = ft_split(str);
    int i = 0;
    while (r[i])
        printf("[%s]", r[i++]);
    printf("\n");
    i = 0;
    while (r[i])
        free(r[i++]);
    free(r);
}
int main(void) {
    print_split("hello world");
    print_split("  spaces  everywhere  ");
    print_split("one");
    print_split("");
    print_split("a\tb\nc");
    return 0;
}'
    if [ ! -f "$TMP/test_ft_split" ]; then bad_compile ft_split
    else
        SP=$($TMP/test_ft_split)
        check 'split("hello world")'           "[hello][world]"       "$(sed -n '1p' <<< "$SP")"
        check 'split("  spaces  everywhere  ")' "[spaces][everywhere]" "$(sed -n '2p' <<< "$SP")"
        check 'split("one")'                   "[one]"                "$(sed -n '3p' <<< "$SP")"
        check 'split("")'                      ""                     "$(sed -n '4p' <<< "$SP")"
        check 'split("a\tb\nc") tabs+newlines' "[a][b][c]"            "$(sed -n '5p' <<< "$SP")"
    fi
fi

# ================================================================
#  SUMMARY
# ================================================================
printf "\n${BOLD}════════════════════════════════${NC}\n"
TOTAL=$((PASS + FAIL))
printf "${BOLD}  Results: ${GREEN}%d passed${NC}  ${RED}%d failed${NC}  / %d total${NC}\n" \
    $PASS $FAIL $TOTAL
if [ $FAIL -eq 0 ] && [ $TOTAL -gt 0 ]; then
    printf "${GREEN}${BOLD}  All tests passed! 🎉${NC}\n"
fi
printf "${BOLD}════════════════════════════════${NC}\n\n"
