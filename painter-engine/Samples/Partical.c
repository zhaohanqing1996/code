//���ڸ���ҽ���PainterEngine����ϵͳ�ı�д
//�����漰���ű������ͼƬ����,����㲻��Ϥ�ⲿ�ֵ�����,����ת��PainterEngineϵ�н̵̳ĵ�һ ���� �� ���߿�
//��Ҫ����һ������ϵͳ,������ҪΪ�������ϵͳ׼��һ������,һ�������������ɺͼ���Ľű��ļ�

//�������Ѿ�׼������һ�����ε�����,����Խ���������滻�����Լ���Ҫ������,����traw��ʽ����������㲻��Ϥ���Բ��ĵ�����
//����������Ҫ׼���ű�,����ϵͳ�Ľű���һ��ģ��,�������KernelĿ¼���ҵ���
//���ڱ�������ű�
//����������������ο����߿�

//���ڰ�����ϵͳ����д����

#include "./PainterEngine/PainterEngineHelper.h"

px_texture star;
PX_ScriptVM_Instance shell;
int main()
{
	PX_Initialize("����ϵͳ",800,600);
	PX_SetBackgroundColor(PX_COLOR(255,0,0,0));//�ѱ������ɺ�ɫ
	PX_LoadTextureFromFile(PX_GetMP(),&star,"star.traw");
	PX_LoadScriptInstanceFromFile(PX_GetMP(),&shell,"ParticalScript.bin");
	PX_Object_ParticalCreate(PX_GetUiRoot(),400,300,&star,&shell,"Partical_Init","Partical_Create",PX_NULL);//�������ӷ�����,������ͽű�Partical_Init�ǽű������ӷ�������ʼ������
	//Partical_Create�����ӷ�������������,���һ��
	//�Ǹ��º���,��Ϊ����Ҫ����дPX_NULL
	while(PX_Loop());
}

