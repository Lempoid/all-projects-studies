#include <slist.h>

int main()
{
    slist_t* list = SListCreate();

    printf("%d", list==NULL);

    void SListDestroy(slist_t *list);

    slist_iter_t SListBegin(const slist_t *list);

    slist_iter_t SListEnd(const slist_t *list);

    slist_iter_t SListNext(slist_iter_t iter);

    int SListIterIsEqual(slist_iter_t one, slist_iter_t other);

    void *SListGetData(slist_iter_t iter);

    void SListSetData(slist_iter_t iter, void *data);

    slist_iter_t SListInsert(slist_t *list,slist_iter_t where, void *data);

    slist_iter_t SListRemove(slist_iter_t iter);

    int SListIsEmpty(const slist_t *list);

    size_t SListCount(const slist_t *list);

    slist_iter_t SListFind(slist_iter_t from,
                            slist_iter_t to,
                            match_func_t is_match_func,
                            void *param);

    int SListForEach(slist_iter_t from,
                    slist_iter_t to,
                    action_func_t action_func, void *param);

    return 0;
}
