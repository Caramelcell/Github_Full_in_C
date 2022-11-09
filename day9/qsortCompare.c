int qsortCompare12(const void* num1, const void* num2) {
	return (*(int*)num1 - *(int*)num2);
}
int qsortCompare21(const void* num1, const void* num2) {
	return (*(int*)num2 - *(int*)num1);
}