#include <stdio.h>
#include <stdlib.h>
/*
 * Description
    输入3 4 5 6 7 9999一串整数，9999代表结束，通过头插法新建链表，并输出，
    通过尾插法新建链表并输出。
注意输出要采用如下代码（因为OJ判题对空格敏感，因此需要用下面的打印代码来做）：
//打印链表中每个结点的值
void PrintList(LinkList L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%d",L->data);//打印当前结点数据
        L=L->next;//指向下一个结点
        if(L!=NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}
Input
3 4 5 6 7 9999，第二行也是3 4 5 6 7 9999，数据需要输入两次
Output
如果输入是3 4 5 6 7 9999，那么输出是7 6 5 4 3，数之间空格隔开，尾插法的输出是3 4 5 6 7
 * */
typedef int ElemType;
typedef struct LNode{
    ElemType data;//数据域
    struct LNode* next;//指针域
}LNode,*LinkList;
//LNode*等价于LinkList

//头插法新建链表
bool list_head_insert(LNode* &L){
    L=(LinkList)malloc(sizeof(LNode));//为头结点申请空间
    L->next=NULL;
    LinkList s;//用于存储新节点
    ElemType x;
    scanf("%d",&x);
    while(x!=9999){
        s=(LinkList) malloc(sizeof(LNode));//为新节点申请空间
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return true;
}
//尾插法新建链表
bool list_tail_insert(LinkList &L){
    L=(LinkList) malloc(sizeof(LNode));//为头结点申请空间
    ElemType x;
    LinkList s,r=L;//s用于存放新节点，r代表链表表尾结点，指向链表尾部
    scanf("%d",&x);
    while(x!=9999){
        s=(LinkList) malloc(sizeof(LNode));//为新节点申请空间
        s->data=x;
        r->next=s;//让尾部节点指向新节点
        r=s;//r指向新的尾部节点
        scanf("%d",&x);
    }
    r->next=NULL;//尾结点的next指针赋值为NULL
    return true;

}
//打印链表中每个结点的值
void PrintList(LinkList L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%d",L->data);//打印当前结点数据
        L=L->next;//指向下一个结点
        if(L!=NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}
int main() {
    LinkList L;
    bool ret;
    ret=list_head_insert(L);
    PrintList(L);
    ret= list_tail_insert(L);
    PrintList(L);
    return 0;
}
