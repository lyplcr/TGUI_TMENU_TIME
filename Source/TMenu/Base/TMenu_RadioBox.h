/* ----------------------------------------------------------------------------
 *                TMenu��ѡ��ʵ��
 * --------------------------------------------------------------------------*/

#ifndef __T_MENU_RADIO_BOX_H 
#define __T_MENU_RADIO_BOX_H

#include "TMenuBase.h"

/**********************************************************************
                      ������
**********************************************************************/
//���嵥ѡ��ťĬ����ʽ(��TWidget.h�뵥ѡ�ؼ�):
#define   TM_RADIO_BOX_STYLE_DEFAULT    \
  (TWIDGET_EN_HEADER | TWIDGET_EN_VSCOLL | TWIDGET_EN_NOTIFY)

//ע:���õ���:
//#define   TWIDGET_EN_FRAME    0x80  //�ù������б߿�,��LC�߶�>-3��ʱ������Ч
//#define   TWIDGET_EN_HEADER   0x40  //������ʾ����ͷ
//#define   TWIDGET_EN_HSCOLL   0x20  //������ʾˮƽ������
//#define   TWIDGET_EN_VSCOLL   0x10  //������ʾ��������
//#define   TWIDGET_EN_NOTIFY   0x04  //�޹�������߿�ʱ�������û���ʱ��ʾ��ʾ��Ϣ
//#define   TRADIO_BUTTOM_EN_RETURN  0x02      //������������

/**********************************************************************
                     �û�ʹ�����
**********************************************************************/
//��Ϊ��ѡ��ʱ,�˵��ṹ�����¶���:
//typedef struct _TMenu{
//  TMTYPE_RADIOBOX;        //�˵�����Ϊ��ѡ��ģʽ
//  unsigned char Size;     //�ɹ�ѡ��ĵ��������
//  LanguageCode_t *pgHeader; //�˵�ͷ,ΪNULLʱ�ӻص����ȡ
//  struct _TMenu *pParent;   //���ѵĸ��˵�
//  const LanguageCode_t*;   //���ÿһ�������������(�ṹ)����
//  TMenuNotify_t Notify;     //���û��ռ佻����ͨ������
//}TMenu_t;

//��ѡ��ģʽ�û�����־Ϊ
#define   TM_RADIOBOX_EN_SAVE   0x80  //�б��水ť��־

//�û������ݽṹ:
struct _RadioBoxUser{
 TItemSize_t Sel;               //ѡ����
};
//�û��ص�������Ӧ���ͼ���ʵ�ֵĹ�����:
//1:����Ϊ:TM_NOTIFY_GET_DATAʱ,�轫��ǰ��ѡװ��Sel��
//2:����Ϊ:TM_NOTIFY_CHANGEDʱ,��ʾSel���ʱ�ı���,
//�û��ɸ���Ӧ��Ҫ������Ƿ���Ӧ(��:�����ֱ�Ӹ���Ӧ��)
//3:����Ϊ:TM_NOTIFY_SET_DATAʱ,��ʾ���޸����,�û�Ӧ���б���Ȳ���

/**********************************************************************
                     �ڲ����ݽṹ
**********************************************************************/
struct _RadioBoxData{
 TRadioButtom_t  RadioButtom;   //�ṹ����
 unsigned char Flag;            //�ڲ���־
 struct _RadioBoxUser User;     //�û�����
};

//------------------------��������ʵ��----------------------------
//1:���������Ͳ˵�,���û���������ݲ�������ʾ
//���ش����ɹ�:
signed char TMenu_RadioBoxCreate(const TMenu_t *pMenu,    //ָ��Ĳ˵�ϵͳ
                                 TWinHandle_t hWin,       //������˵��Ĵ���
                                 unsigned char Data,    //�������������,����������
                                 void *pv);      //�ɹ�ʹ�õ����ɻ�����

//------------------------��Ӧ��������ʵ��----------------------------
//2:��Ӧ��������������������û��������ݽ���,��������ʾ
//����ֵ����Ϊ: ��ֵ:������Ӧ�Ӳ˵�,-1,����,-2:�����ϲ�˵�
signed char TMenu_RadioBoxKey(const TMenu_t *pMenu,    //ָ��Ĳ˵�ϵͳ
                              unsigned char Key,       //����ļ�ֵ
                              void *pv);      //�ѱ�ʹ�õ��������ݻ�����

//-------------------------��ѡ��ͨ���ص�ʵ�ֺ���-----------------------------
//�����ڲ�ͨ��ʹ��
const void*TMenu_RadioBoxNotify(void *pvPource,
                                unsigned char Type,
                                const void *pvData);

/**********************************************************************
                      �ص�����
**********************************************************************/

//----------------------�õ���ǰ��ʾ��ʽ-------------------------
#ifdef TMENU_STYLE_VARIABLE   //�ɱ���ʽʱ���û�������
  unsigned char TMenu_RadioBox_cbGetCurStyle(void);
#else
  #define TMenu_RadioBox_cbGetCurStyle() \
    (TM_RADIO_BOX_STYLE_DEFAULT | TRADIO_BUTTOM_EN_RETURN)
#endif


#endif