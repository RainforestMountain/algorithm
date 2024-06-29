#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 3
typedef struct jcb
{
    char name[10]; // 进程名
    int reqtime;   // 要求服务时间
    int prio;      // 优先级
    int runtime;   // 运行时间
    char status;
} PCB;
int intarr = 0, intfin = 0; // 到达进程个数，完成进程个数
PCB pcbarr[24], pcbfin[24];

void Mune()
{
    printf("\n\n");
    printf("\t\t|------------------------------------------------|\n");
    printf("\t\t|                 进程调度模拟程序               |\n");
    printf("\t\t|------------------------------------------------|\n");
    printf("\t\t|       0:退出                                   |\n");
    printf("\t\t|       1:运行（最高优先级优先算法）             |\n");
    printf("\t\t|       2:插入                                   |\n");
    printf("\t\t|       3:删除                                   |\n");
    printf("\t\t|------------------------------------------------|\n");
    printf("请选择<0~3>：");
}
void Input() // 手动输入
{
    int i;
    int n = 0;
    printf("请输入进程个数:");
    scanf("%d", &n);
    for (i = 0; i < n; i++, intarr++)
    {
        printf("\n第%d个进程：\n请输入进程名:", i + 1);
        scanf("%s", pcbarr[intarr].name);
        printf("请输入要求服务时间:");
        scanf("%d", &pcbarr[intarr].reqtime);
        pcbarr[intarr].prio = N; // 优先级为3
        if (i == 0)
            pcbarr[intarr].status = 'r';
        else
            pcbarr[intarr].status = 'w';
    }
}

void Output() // 输出排序后队列
{
    int i = 0;
    printf("\n\n运行队列的是\n");
    printf("\tname\treqtime\truntime\tprio\tstatus\n");
    if (intarr != 0)
    {
        printf("N%d\t%s\t%d\t%d\t%d\t%c\n", i, pcbarr[i].name, pcbarr[i].reqtime, pcbarr[i].runtime, pcbarr[i].prio, pcbarr[i].status);
    }
    printf("\n就绪队列的是\n");
    printf("\tname\treqtime\truntime\tprio\tstatus\n");
    for (i = 1; i < intarr; i++)
    {
        printf("N%d\t%s\t%d\t%d\t%d\t%c\n", i, pcbarr[i].name, pcbarr[i].reqtime, pcbarr[i].runtime, pcbarr[i].prio, pcbarr[i].status);
    }
    printf("\n已完成队列的是\n");
    printf("\tname\treqtime\truntime\tprio\tstatus\n");
    for (i = 0; i < intfin; i++)
    {
        printf("N%d\t%s\t%d\t%d\t%d\t%c\n", i, pcbfin[i].name, pcbfin[i].reqtime, pcbfin[i].runtime, pcbfin[i].prio, pcbfin[i].status);
    }
    printf("\n*********************************************\n");
}

// 按优先级排序
void Sort()
{
    int i, j;
    PCB temp;
    for (i = 0; i < intarr - 1; i++)
    {
        for (j = i + 1; j < intarr; j++)
        {
            if (pcbarr[i].prio < pcbarr[j].prio)
            {
                temp = pcbarr[i];
                pcbarr[i] = pcbarr[j];
                pcbarr[j] = temp;
            }
        }
    }
    pcbarr[0].status = 'r';
    for (i = 1; i < intarr; i++)
    {
        pcbarr[i].status = 'w';
    }
}
void running()
{
    int slice, i, k;
    slice = 1;

    for (i = 1; i < ((N + 1) - pcbarr[0].prio); i++)
        slice = slice * 2;

    for (i = 1; i <= slice; i++)
    {
        pcbarr[0].runtime++;
        if (pcbarr[0].runtime == pcbarr[0].reqtime)
            break;
    }

    if (pcbarr[0].runtime == pcbarr[0].reqtime)
    {
        printf("\n 进程 [%s] 已完成.\n", pcbarr[0].name);
        pcbfin[intfin] = pcbarr[0];
        for (k = 0; k <= intarr; k++)
        {
            pcbarr[k] = pcbarr[k + 1];
        }
        intarr--;
        intfin++;
    }
    else
    {
        if (pcbarr[0].prio > 1)
            pcbarr[0].prio--;
    }
}

void Delete()
{
    char b[20];
    int i, j, key = 0;
    printf("请输入要删除的进程名：");
    scanf("%s", b);
    for (i = 0; i < intarr; i++)
    {
        if (strcmp(b, pcbarr[i].name) == 0)
        {
            key = 1;
            for (j = i; j <= intarr; j++)
            {
                pcbarr[j] = pcbarr[j + 1];
            }
            intarr--;
        }
    }
    for (i = 0; i < intfin; i++)
    {
        if (strcmp(b, pcbfin[i].name) == 0)
        {
            key = 1;
            for (j = i; j <= intfin; j++)
            {
                pcbfin[j] = pcbfin[j + 1];
            }
            intfin--;
        }
    }
    if (key == 0)
    {
        printf("查找不到该进程！");
    }
}
int main()
{
    int chose;
    Input();
    Output();
    while (1)
    {
        Mune();
        scanf("%d", &chose);
        switch (chose)
        {
            case 0:
                exit(0);
                break;
            case 1:
                running();
                break;
            case 2:
                Input();
                break;
            case 3:
                Delete();
                break;
            default:
                printf("输入错误!");
        }
        Sort();
        Output();
    }
}
