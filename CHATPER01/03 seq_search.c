int seq_search(int list[], int n, int key)//(배열,배열의크기,찾으려는 값) 배열에서 값 찾기 
{
	int i;
	for (i = 0; i < n; i++)
		if (list[i] == key)
			return i;  //찾을려는 Key값이 있는 배열의 인댁스 return
	return -1;    
}