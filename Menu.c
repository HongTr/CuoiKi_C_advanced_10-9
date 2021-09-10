#include "Graphlib.h"

int main(){
    FILE* source;
    source = fopen("tiepXucGan.txt", "r");
    if (source == NULL){
        printf("Error!\n");
        exit(1);
    }
    
    Graph graph = createGraph();
    int choice;
    int flag = 0;
    do{
        printf("=====================================\n");
        printf("1. Chuc nang 1\n");
        printf("2. Chuc nang 2\n");
        printf("3. Chuc nang 3\n");
        printf("4. Chuc nang 4\n");
        printf("5. Chuc nang 5\n");
        printf("6. Chuc nang 6\n");
        printf("7. Chuc nang 7\n");
        printf("8. Chuc nang 8\n");
        printf("9. Chuc nang 9\n");
        printf("10. Chuc nang 10\n");
        printf("=====================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        if (choice <= 0 || choice >= 11) printf("Nhap khong hop le!\n");
        else if (choice >=1 && choice <=10){
            switch(choice){
                case 1:
                    if (!flag){
                        flag = 1;
                        // read file
                        int so_nguoi;
                        char ten_nguoi[2];
                        fscanf(source, "%d\n", &so_nguoi);
                        char* token;
                        char str[10];
                        for (int i = 0; i < so_nguoi; i++){
                            fscanf(source, "%s", &ten_nguoi);
                            addVertex(graph, convert(ten_nguoi), ten_nguoi);

                            fgets(str, 10, source);
                            token = strtok(str, " ");
                            //printf("%d", convert(token));
                            while(token != NULL){
                                addEdge2(graph, convert(ten_nguoi), convert(token), 1);
                                token = strtok(NULL, " ");
                            }
                        }
                        printf("Da hoan thanh doc file!\n");
                    }
                    else printf("Ban da doc file\n");
                    break;
                case 2:
                    if (flag){
                        JRB temp;
                        int adj[10], sl;
                        jrb_traverse(temp, graph.vertices){
                            printf("%c ", reconvert(jval_i(temp->key)));
                            sl = indegree(graph, jval_i(temp->key), adj);
                            for (int i = 0; i < sl; i++){
                                printf("%c ", reconvert(adj[i]));
                            }
                            printf("\n");
                        }
                    }
                    else printf("Ban chua doc file!\n");
                    break;
                case 3:
                    if (flag){
                        char A[2], B[2];
                        printf("Nhap vao nguoi 1: "); fflush(stdin);
                        gets(A);
                        printf("Nhap vao nguoi 2: "); fflush(stdin);
                        gets(B);
                        int iA = convert(A);
                        int iB = convert(B);
                        if (hasEdge(graph, iA, iB)) printf("Co tiep xuc gan!\n");
                        else printf("Khong tiep xuc gan!\n");
                    }
                    else printf("Ban chua nap do thi!\n");
                    break;
                case 4:
                    if (flag){
                        char A[2];
                        printf("Nhap ten: "); fflush(stdin);
                        gets(A);
                        int txgan[10];
                        int sl;
                        sl = indegree(graph, convert(A), txgan);
                        printf("Danh sach tiep xuc gan la: ");
                        for (int i = 0; i < sl; i++){
                            printf("%c ", reconvert(txgan[i]));
                        }
                        printf("\n");
                    }
                    else printf("Ban chua nap do thi!\n");
                    break;
                case 5:
                    if (flag){
                        int imax = -1;
                        int in;
                        JRB temp;
                        jrb_traverse(temp, graph.vertices){
                            int input[10];
                            in = indegree(graph, jval_i(temp->key), input);
                            if (in > imax) imax = in;
                        }
                        printf("Danh sach nhung nguoi tiep xuc gan nhieu nhat: ");
                        jrb_traverse(temp, graph.vertices){
                            int input[10];
                            if (imax == indegree(graph, jval_i(temp->key), input)) 
                                printf("%c ", reconvert(jval_i(temp->key)));
                        }
                        printf("\n");
                    }
                    else printf("Ban chua nap do thi!\n");
                    break;
                case 6:
                    if (flag){
                        char fo[2];
                        printf("Nhap ten nguoi nghi nhiem: ");
                        fflush(stdin); gets(fo);
                        //F1
                        int sl_f1, f1[10];
                        sl_f1 = indegree(graph, convert(fo), f1);
                        printf("Danh sach f1: ");
                        for (int i = 0; i < sl_f1; i++){
                            printf("%c ", reconvert(f1[i]));
                        }
                        printf("\n");
                        //F2
                        float d;
                        int path[10];
                        JRB temp;
                        printf("Danh sach f2: ");
                        jrb_traverse(temp, graph.vertices){
                            int length;
                            d = dijkstra(graph, convert(fo), jval_i(temp->key), path, &length);
                            if (d == 2) printf("%c ", reconvert(jval_i(temp->key)));
                        }
                        printf("\n");
                    }   
                    else printf("Ban chua nap do thi!\n");
                    break;
                case 7:
                    if (flag){
                        char x[2], tx[2];
                        printf("Nhap ten nguoi moi: "); fflush(stdin);
                        gets(x);
                        addVertex(graph, convert(x), x);
                        int c;
                        do{
                            printf("Nhap nguoi tiep xuc gan: "); fflush(stdin);
                            gets(tx);
                            addEdge2(graph, convert(x), convert(tx), 1);

                            printf("Ban muon nhap nua khong? (1/0) "); scanf("%d", &c);
                        }while(c != 0);
                        printf("Danh sach tiep xuc gan\n");
                        JRB temp;
                        int adj[10], sl;
                        jrb_traverse(temp, graph.vertices){
                            printf("%c ", reconvert(jval_i(temp->key)));
                            sl = indegree(graph, jval_i(temp->key), adj);
                            for (int i = 0; i < sl; i++){
                                printf("%c ", reconvert(adj[i]));
                            }
                            printf("\n");
                        }
                    }
                    else printf("Ban chua nap do thi!\n");
                    break;
                case 8:
                    if (flag){
                        char x1[2], x2[2];
                        do{
                            printf("Nhap ten nguoi 1: "); fflush(stdin);
                            gets(x1);
                            printf("Nhap ten nguoi 2: "); fflush(stdin);
                            gets(x2);

                            if (getVertex(graph, convert(x1)) == NULL || getVertex(graph, convert(x2)) == NULL){
                                printf("Nhap ten khong hop le!\n");
                            }
                        }while(getVertex(graph, convert(x1)) == NULL || getVertex(graph, convert(x2)) == NULL);

                        addEdge2(graph, convert(x1), convert(x2), 1);
                        printf("Danh sach tiep xuc gan\n");
                        JRB temp;
                        int adj[10], sl;
                        jrb_traverse(temp, graph.vertices){
                            printf("%c ", reconvert(jval_i(temp->key)));
                            sl = indegree(graph, jval_i(temp->key), adj);
                            for (int i = 0; i < sl; i++){
                                printf("%c ", reconvert(adj[i]));
                            }
                            printf("\n");
                        }
                    }
                    else printf("Ban chua nap do thi!\n");
                    break;
                case 9:;
                    FILE* target;
                    target = fopen("GhiRaFile.txt", "w+");
                    JRB temp;
                    int sl_tx, tx[10];
                    jrb_traverse(temp, graph.vertices){
                        sl_tx = indegree(graph, jval_i(temp->key), tx);
                        fprintf(target, "%c ", reconvert(jval_i(temp->key)));
                        for (int i = 0; i < sl_tx; i++){
                            fprintf(target, "%c ", reconvert(tx[i]));
                        }
                        fprintf(target, "\n");
                    }
                    fclose(target);
                    break;
                case 10: printf("Ban da thoat chuong trinh!\n");
                    break;
            }
        }
    }while(choice != 10);
    fclose(source);
    return 1;
}