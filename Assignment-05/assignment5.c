#include<stdio.h>

//Convert Secs To Minute
int *min_sec(int sec)
{
	static int m_s[2];
	m_s[0]=(int)(sec/60);
	m_s[1]=sec-m_s[0]*60;
	return m_s;
}

//Convert Mins To Hours
int *hr_min(int min)
{
	static int h_m[2];
	h_m[0]=(int)(min/60);
	h_m[1]=min-h_m[0]*60;
	return h_m;
}

void main()
{
	int i;
	int *ms;
	int *hm;
	int sec;
	
	printf("Enter Seconds : ");
	scanf("%d",&sec);
	ms=min_sec(sec);

	hm=hr_min(*(ms));
	printf("%d seconds is equal to %d hours %d minutes and %d seconds",sec,*hm,*(hm+1),*(ms+1));
}
