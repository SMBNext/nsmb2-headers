#include "types.h"

class fBase;

class ProcessMgr                                                               // size: 0x11430
{
public:
        
    struct TreeNode                                                         // size: 0x14
    {
        TreeNode();                                                         // 0x00104F64

        fBase* getProc();                                                   // 0x00496F10
        TreeNode* getNext();                                                // 0x00496F38   returns child, nextSibling or parent->nextSibling
        TreeNode* getNextToRight();                                         // 0x00496F84   returns nextSibling or parent->nextSibling if former doesn't exist

        fBase* proc;                                                        // Inited to nullptr
        TreeNode* parent;                                                   // Inited to nullptr
        TreeNode* fistChild;                                                // Inited to nullptr
        TreeNode* prevSibling;                                              // Inited to nullptr
        TreeNode* nextSibling;                                              // Inited to nullptr
    };
    
    struct ListNode                                                         // size: 0x10
    {
        ListNode();                                                         // 0x00104F48

        fBase* getProc();                                                   // 0x00496F10
        void setPriorities(u16 val);                                        // 0x001C71B8   sets _c and _E
        bool prioritiesAreEqual();                                          // 0x00496F18
        
        ListNode* prev;                                                     // Inited to nullptr
        ListNode* next;                                                     // Inited to nullptr
        fBase* proc;                                                        // Inited to nullptr
        u16 priority1;                                                      // List priority. Inited to 0
        u16 priority2;                                                      // ^
    };
    
    struct Tree                                                             // size: 0x4
    {
        Tree();                                                             // 0x00104F3C

        TreeNode* getByProfileId(s16 profileId, TreeNode* node);            // 0x00496EB0

        bool insert(TreeNode* node, TreeNode* parent);                      // 0x001C70B0
        bool remove(TreeNode* node);                                        // 0x001C713C
        
        TreeNode* root;                                                     // Inited to nullptr
    };
    
    struct List                                                             // size: 0x8
    {
        List();                                                             // 0x00104F2C

        ListNode* getById(s32 id);                                          // 0x00496DEC
        bool prepend(ListNode* node);                                       // 0x001C6360
        bool append(ListNode* node);                                        // 0x001C63F8
        bool insertOrdered(ListNode* node);                                 // 0x001C6428   orders by node->_C (ascending)
        bool remove(ListNode* node);                                        // 0x001C6390
        
        ListNode* first;                                                    // Inited to nullptr
        ListNode* last;                                                     // Inited to nullptr
    };

public:
    static ProcessMgr* getInstance();                                                   // 0x001C550C
    static fBase* createProcess(u16 profileId, fBase* parent, u32 settings, u8 unk);    // 0x004576EC

    fBase* create(u16 profileId, u32 settings, u8 unk);                         // 0x001C52F0
    fBase* create(u16 profileId, fBase* parent, u32 settings, u8 unk);          // 0x001C5324
    void erase(fBase* proc);                                                    // 0x001C5BA4

    fBase* getRootProc();                                                   // 0x00496A5C
    fBase* getProcByProfileId(s16 profileId, fBase* parent = nullptr);      // 0x00496D7C
    fBase* getFirstProcChild(fBase* proc);                                  // 0x00496A7C
    fBase* getNextProcSibling(fBase* proc);                                 // 0x00496B44
    fBase* getParentProc(fBase* proc);                                      // 0x00496BB4
    s32 getNextId();                                                        // 0x00496AD4
    
    void enableCreate(s32 id);                                              // 0x001C60F4
    void disableCreate(s32 id);                                             // 0x001C6128
    bool isCreateDisabled(s32 id);                                          // 0x00496D24

    void enableDelete(s32 id);                                              // 0x001C5C60
    void disableDelete(s32 id);                                             // 0x001C5C94

    void disableDraw(s32 id);                                               // 0x001C615C

    static inline s32 idxForId(s32 id)                                      // used to fetch List/Tree nodes for a specific id from arrays
    {
        if (id < 0x400 || (id & 0x3FF) >= 0x200)
            return id & 0x3FF;
        else
            return (id & 0x3FF) + 0x200;
    }

    static ProcessMgr* instance;                                               // 0x005F3980

    TreeNode treeNodes[0x400];                                              // manages proc hierarchy 
    ListNode listNodes[0x400];                                              // uses execute priorities
    ListNode drawNodes[0x400];                                              // uses draw priorities
    Tree tree;
    List createList;                                                        // unordered (new nodes are appended)
    List executeList;                                                       // ordered
    List drawList;                                                          // ordered
    List deleteList;                                                        // unordered (new nodes are prepended)
    ListNode searchNodes[0x400];
    List searchList;                                                        // unordered (new nodes are prepended)
    u8 operationDisable[0x400];                                             // Bit 1: Execute, Bit 3: Draw, No effect on Create and Delete? (Bit 0: Create?, Bit 2: Delete?)
    u8 _1142C;                                                              // Inited to 1  Current Operation? 0: none, 2: create, 3: execute 4: delete, 5: draw
    u8 masterOperationDisable;                                              // Inited to 0  Bit 1 disables create, 2 execute 3 delete, 4 draw
};
