/* ----------------------------------------------------------------------------
 *                TMenu�༭ѡ��ģʽʵ��
 *�򲿷ֱ�������ʾ��ʽ��ͬ,���еĴ�����ʾ����������,���������ı��༭���������!
 * --------------------------------------------------------------------------*/

#ifndef __T_MENU_M_EDIT_SEL_H 
#define __T_MENU_M_EDIT_SEL_H

#include "TMenuBase.h"
#include "TMenuBase.h"

#include "TEdit_Float.h"

//˵��:
//�༭ѡ��ģʽ��ָ�ɱ༭�������ڴ˽��б�һ��ʾ��ѡ��ѡ�к�ɽ�����Ӧ�Ӳ˵����е���
//��ʾʾ��Ϊ(����ʾ):
//  
//  ��������������ز�������������
//  ��    ���: 002             ��   //��ֵ������
//  ��    ����: �豸��         ��    //�ַ�������
//  ��    ����: ����ģ��       ��    //�ַ����ɵ�����
//  ��������ʽ: ��-���ޱ���    ��    //��ѡ����
//  ��    ��ע: λ���豸���Ա� ��    //�ַ�������
//  ��    [��  ��] [��  ��]     ��
//  ������������������������������

/**********************************************************************
                      ������
**********************************************************************/

//����Ĭ����ʽ(��TWidget.h�븴ѡ�ؼ�):
#define   TM_M_EDIT_SEL_STYLE_DEFAULT    \
  (TWIDGET_EN_HEADER | TWIDGET_EN_VSCOLL | TWIDGET_EN_NOTIFY)

//ע:���õ���:
//#define   TWIDGET_EN_FRAME    0x80  //�ù������б߿�,��LC�߶�>-3��ʱ������Ч
//#define   TWIDGET_EN_HEADER   0x40  //������ʾ����ͷ
//#define   TWIDGET_EN_HSCOLL   0x20  //������ʾˮƽ������
//#define   TWIDGET_EN_VSCOLL   0x10  //������ʾ��������
//#define   TWIDGET_EN_NOTIFY   0x04  //�޹�������߿�ʱ�������û���ʱ��ʾ��ʾ��Ϣ
//#define   TLISTBOXEX_EN_RETURN  0x02      //������������

/**********************************************************************
                     �û�ʹ�����
**********************************************************************/

//��Ϊ�༭ѡ��ģʽʱ,�˵��ṹ�����¶���:
//typedef struct _TMenu{
//  TMTYPE_EDITSEL |TM_MEDITSEL_EN_EDIT //�˵�����Ϊ�༭ѡ��ģʽģʽ���û�����־
//  unsigned char Size;     //�ɹ�ѡ��ĵ��������
//  LanguageCode_t *pgHeader; //�˵�ͷ,ΪNULLʱ�ӻص����ȡ
//  struct _TMenu *pParent;   //���ѵĸ��˵�
//  const TMenu_t*;           //������ѵ��Ӳ˵���������ͷ
//  TMenuNotify_t Notify;     //���û��ռ佻����ͨ������
//}TMenu_t;

//�˵����ͻ�����־��Ϊ:
//��ֵ�ɵ���,���򲻿ɵ���
#define TM_MEDITSEL_EN_EDIT     (0x01 << TMTYPE_USER_SHIFT)
//��ֵ�ɵ���ʱ,�Ƿ�ΪȺ����ģʽ���д�ģʽʱ��ǿ���б������˳���
//ע��Ⱥ����ģʽ���û���Ӧ�ò����ѻ������޸Ļ򱣴������,����ֻ��
//֪ͨ������
#define TM_MEDITSEL_GRP_SAVE  (0x02 << TMTYPE_USER_SHIFT)   


//�û������ݽṹ
struct _EditSelUser{ 
 //1:��Ӧѡ����
 //2:��Ҫ��ȡ��ǰ�������ַ���ʱ,ָ����Ҫ��ȡ��һ��
 TItemSize_t CurItem;
 const char *pData;//��Ӧ�Ӳ˵���λ�õĵ�ǰ��ֵ
};


//�û��ص�������Ӧ���ͼ���ʵ�ֵĹ�����:
//1:����Ϊ:TM_NOTIFY_GET_DATAʱ,��װ��pData

//2:����Ϊ:TM_NOTIFY_SET_DATAʱ,>=����ʱ֪ͨ�û���������������,
//  �����ʾͨ�������Ӧ��

/**********************************************************************
                     �ڲ����ݽṹ
**********************************************************************/

//�����ڲ����ݽṹ:
struct _EditSelData{
 TListboxEx_t  ListboxEx;       //�ṹ����
 unsigned char HeaderW;        //�����ʾͷ����
 unsigned char ItemsW;        //������ݿ���
 volatile unsigned char Flag;  //�ڲ���־
 struct _EditSelUser User;    //�û�����
};

//------------------------��������ʵ��----------------------------
//1:���������Ͳ˵�,���û���������ݲ�������ʾ
//���ش����ɹ�:
signed char TMenu_EditSelCreate(const TMenu_t *pMenu,    //ָ��Ĳ˵�ϵͳ
                                TWinHandle_t hWin,       //������˵��Ĵ���
                                //�������������,�����ʾ�ϴβ˵�λ��
                                unsigned char Data,
                                void *pv);      //�ɹ�ʹ�õ����ɻ�����

//------------------------��Ӧ��������ʵ��----------------------------
//2:��Ӧ��������������������û��������ݽ���,��������ʾ
//����ֵ����Ϊ: ��ֵ:������Ӧ�Ӳ˵�,-1,����,-2:�����ϲ�˵�
signed char TMenu_EditSelKey(const TMenu_t *pMenu,    //ָ��Ĳ˵�ϵͳ
                             unsigned char Key,       //����ļ�ֵ
                             void *pv);      //�ѱ�ʹ�õ��������ݻ�����

//-----------------------�༭ѡ��ģʽ�п��ͨ���ص�ʵ�ֺ���------------------------
//�����ڲ�ͨ��ʹ��
const void*TMenu_EditSelListBoxNotify(void *pvPource,
                                      unsigned char Type,
                                      const void *pvData);

//-----------------�༭ģʽͨ���ص�ʵ�ֺ���------------------------
//�����ڲ�ͨ��ʹ��
const void*TMenu_EditSelEditNotify(void *pvPource,
                                   unsigned char Type,
                                   const void *pvData);

/**********************************************************************
                     �ص�����
**********************************************************************/

//----------------------�õ���ǰ��ʾ��ʽ-------------------------
#ifdef TMENU_STYLE_VARIABLE   //�ɱ���ʽʱ���û�������
  unsigned char TMenu_EditSel_cbGetCurStyle(void);
#else
  #define TMenu_EditSel_cbGetCurStyle() \
    (TM_M_EDIT_SEL_STYLE_DEFAULT | TLISTBOXEX_EN_RETURN)
#endif

#endif