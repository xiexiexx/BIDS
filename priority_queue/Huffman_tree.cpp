#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Huffman树结点定义
struct hnode {
  vector<bool> code;
  double weight;
  // 设原始符号共n个, 以编号number区分原始符号结点(0到n - 1)和编码过程中出现的新结点.
  size_t number;
  hnode* left;
  hnode* right;
};

int main()
{
  // 依次设置26个字母的频率存于P中.
  vector<double> P {0.0721, 0.0240, 0.0394, 0.0372, 0.1224, 0.0272, 0.0178,
                    0.0449, 0.0779, 0.0013, 0.0054, 0.0426, 0.0282, 0.0638,
                    0.0681, 0.0290, 0.0023, 0.0638, 0.0728, 0.0908, 0.0235,
                    0.0094, 0.0130, 0.0077, 0.0126, 0.0026};
  // 存储Huffman树的最小优先级队列PQ, 优先级为树的权值, 实际存储的是树的根结点指针.
  auto cmp = [](hnode* a, hnode* b) { return a->weight > b->weight; };
  priority_queue<hnode*, vector<hnode*>, decltype(cmp)> PQ(cmp);
  // 一次性给出所有在编码中会出现的结点, 以数据向量D存储.
  vector<hnode> D(P.size() > 0 ? 2 * P.size() - 1 : 0);
  // index指示当前会使用D[index]处的结点, 注意其作用域不仅限于下面的for循环.
  size_t index;
  // D中初始设定n棵仅有根结点的树, 并放入优先级队列PQ中.
  for (index = 0; index < P.size(); ++index)
  {
    D[index] = {{}, P[index], index, NULL, NULL};
    PQ.push(&D[index]);
  }
  // 循环处理以构建Huffman树.
  while (PQ.size() > 1)
  {
    D[index].number = index;
    // 将优先级队列中的最小元作为当前结点的左孩子并删去最小元.
    D[index].weight = PQ.top()->weight;
    D[index].left = PQ.top();
    PQ.pop();
    // 将优先级队列中的最小元作为当前结点的右孩子并删去最小元.
    D[index].weight += PQ.top()->weight;
    D[index].right = PQ.top();
    PQ.pop();
    // 将新的树放入优先级队列并且更新编号index.
    PQ.push(&D[index++]);
  }
  // 打印每个字母的Huffman编码.
  queue<hnode*> Q;
  if (!PQ.empty())
    Q.push(PQ.top());
  while (!Q.empty())
  {
    hnode* current = Q.front();
    if (current->left != NULL)
    {
      Q.push(current->left);
      current->left->code = current->code;
      current->left->code.push_back(false);
    }
    if (current->right != NULL)
    {
      Q.push(current->right);
      current->right->code = current->code;
      current->right->code.push_back(true);
    }
    Q.pop();
  }
  for (size_t i = 0; i < P.size(); ++i)
  {
    cout << (char)('A' + i) << "->";
    for (auto x : D[i].code)
      cout << (x ? '1' : '0');
    cout << ' ' << endl;
  }
  return 0;
}
