#include<bits/stdc++.h>
using namespace std;

//判断语句块类型
int judge(string dat, int i){
	//WA3:当前位置是if并且不是在字符串内
	if(dat.find("if", i)==i && (dat[i+2]==' '||dat[i+2]=='('))return 2;
	if(dat.find("for",i)==i && (dat[i+3]==' ' ||dat[i+3]=='('))return 3;
    if(dat.find("while",i)==i && (dat[i+5]==' '||dat[i+5]=='('))return 5;
    if(dat.find("else",i)==i && dat[i+4]==' ')return 4;
	return 0;//普通语句
}
//输出前删除多余空格, 并输出当前对应的空格
void erase_space(string dat,int &i){while(dat[i]==' ')i++;}
void print_space(int sp){for(int i=0;i<sp;i++)putchar(' ');}

int main(){
	string dat;  getline(cin,dat);
	
	//处理int main()  找i和)输出
	int l = dat.find('i',0), r = dat.find(')',0);
	cout<<dat.substr(l,r-l+1)<<"\n{\n";
	
	//处理其他，按照行分类
	int tmp, space = 2;//语句类型,空格数
	int flag, debt=0;//单句标记，层数（补全缺少的}）
	for(int i = dat.find('{')+1,j=0,k; i < dat.size(); ){
		erase_space(dat,i);//删除每行前的空格
		if(dat[i]=='{' || dat[i]=='}'){
			if(dat[i]=='{'){
				print_space(space);
				printf("{\n");
				space += 2;
				i++;
				continue;
			}else{
				space -= 2;
				print_space(space);
				printf("}\n");
				i++;
				if(space==0)break;//main的}输完就结束了
				
				//【重复】单句特判
				erase_space(dat,i);
				while(debt && judge(dat,i)!=4){
					space -= 2;
					print_space(space);
					printf("}\n");
					debt--;
				}
			}
		}else if((tmp=judge(dat,i))){
			print_space(space);
			//处理for,while,if,+()或者else
			if(tmp==4){
				printf("else");
				k = i+3;
			}else{
				cout<<dat.substr(i,tmp)<<" ";
				i += tmp;
				erase_space(dat, i);
				//考虑if()中也有()条件的情况
				k = i; int t = 0;
				while(1){
					if(dat[k]=='(')t++;
					if(dat[k]==')')t--;
					if(!t)break;
					k++;
				}
				cout<<dat.substr(i,k-i+1);
			}
			//预处理{}的内容,考虑单句特判
			int m = k+1;
			erase_space(dat,m);
			if(dat[m] != '{'){//单句标记
				printf(" {\n");
				flag = 1;
				debt++;
				i = m;
			}else{
				printf(" {\n");
				flag = 0;
				i = m+1;
			}
			space += 2;
		}else{//普通语句
			int ed = dat.find(';', i);
			print_space(space);
			cout<<dat.substr(i,ed-i+1)<<"\n";
			i = ed+1;
			
			//这是单句内的语句
			if(flag && debt){
				space -= 2;
				print_space(space);
				printf("}\n");
				debt--;
				
				//【重复】单句特判
				erase_space(dat,i);
				while(debt && judge(dat,i)!=4){
					space -= 2;
					print_space(space);
					printf("}\n");
					debt--;
				}
			}
		}
	}
	return 0;
}
