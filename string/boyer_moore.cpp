#include <stdio.h>

int skip[500];

int mstrlen(char* s) {

	int n = -1;
	while (s[++n]);

	return n;
}

void compute_skip(char pattern[], int skip[]){
	int i, j;	
	int len = mstrlen(pattern);

	for (i = 0; i < 500; i++){
		skip[i] = len;
	}

	for (j = 0; j < len - 1; j++){
		skip[pattern[j]] = len - 1 - j;
	}
}

void do_boyer_moore_horspool(char text[], char pattern[]){

	compute_skip(pattern, skip);

	int i = 0, j, k;
	int t_len = mstrlen(text);
	int p_len = mstrlen(pattern);

	while (i <= t_len - p_len){
		j = p_len - 1;
		k = i + p_len - 1;
		
		while (j >= 0 && pattern[j] == text[k]){
			j--; k--;
		}

		if (j == -1){
			printf("matched index : %d\n", i);
		}

		i += skip[text[i + p_len - 1]];
	}
}

int main(void)
{
	char text[1000] = "I am a boy and you are a girl";
	char pattern[500] = "boy";
	do_boyer_moore_horspool(text, pattern);

	return 0;
}