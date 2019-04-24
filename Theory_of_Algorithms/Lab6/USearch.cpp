//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "USearch.h"
#include "UAvto.h"
#include "UMain.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TfrmSearch *frmSearch;
//---------------------------------------------------------------------------
__fastcall TfrmSearch::TfrmSearch(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int FFind(TAvto a,String s) //������� ������� �������� �������� � �����
{
  int k=0;
  if(a.number.Pos(s)>0)
    k++;
  if(a.mark.Pos(s)>0)
    k++;
  if(a.name.last.Pos(s)>0)
    k++;
  if(a.name.first.Pos(s)>0)
    k++;
  if(a.address.street.Pos(s)>0)
    k++;
  if(a.address.house.Pos(s)>0)
    k++;
  if(a.address.flat.Pos(s)>0)
    k++;
  if(a.receipt.Pos(s)>0)
    k++;
  return k;
}
//---------------------------------------------------------------------------
int FSearch(String s) //������� ������� �������� �������� �������� � �� ���� ��� ������
{  
  int k=0,t=1;
  TAvto a;
  FFirst();
  while(FIsEnd()==false)
  {
    a=FGet();    
    k+=FFind(a,s);
    if(FFind(a,s)>0)
    {
      frmSearch->stg->Cells[0][t]=IntToStr(a.id);
      frmSearch->stg->Cells[1][t]=a.number;
      frmSearch->stg->Cells[2][t]=a.mark;
      frmSearch->stg->Cells[3][t]=a.name.last;
      frmSearch->stg->Cells[4][t]=a.name.first;
      frmSearch->stg->Cells[5][t]=a.address.street;
      frmSearch->stg->Cells[6][t]=a.address.house;
      frmSearch->stg->Cells[7][t]=a.address.flat;
      frmSearch->stg->Cells[8][t]=a.receipt;
      t++;
    }
    FNext();
  }
  a=FGet();
  k+=FFind(a,s);
  if(FFind(a,s)>0)
  {
    frmSearch->stg->Cells[0][t]=IntToStr(a.id);
    frmSearch->stg->Cells[1][t]=a.number;
    frmSearch->stg->Cells[2][t]=a.mark;
    frmSearch->stg->Cells[3][t]=a.name.last;
    frmSearch->stg->Cells[4][t]=a.name.first;
    frmSearch->stg->Cells[5][t]=a.address.street;
    frmSearch->stg->Cells[6][t]=a.address.house;
    frmSearch->stg->Cells[7][t]=a.address.flat;
    frmSearch->stg->Cells[8][t]=a.receipt;
    t++;
  }
  frmSearch->stg->RowCount=t;
  return k;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSearch::FormCreate(TObject *Sender)
{
  frmSearch->stg->Cells[0][0]="ID";
  frmSearch->stg->Cells[1][0]="����� ����";
  frmSearch->stg->Cells[2][0]="�����";
  frmSearch->stg->Cells[3][0]="�������";
  frmSearch->stg->Cells[4][0]="��'�";
  frmSearch->stg->Cells[5][0]="������";
  frmSearch->stg->Cells[6][0]="�������";
  frmSearch->stg->Cells[7][0]="��������";
  frmSearch->stg->Cells[8][0]="������";
}
//---------------------------------------------------------------------------
void __fastcall TfrmSearch::btnShawAllClick(TObject *Sender)
{
  TAvto a; 
  int t=1;
  FFirst();
  while(FIsEnd()==false)
  {
    a=FGet();
    frmSearch->stg->Cells[0][t]=IntToStr(a.id);
    frmSearch->stg->Cells[1][t]=a.number;
    frmSearch->stg->Cells[2][t]=a.mark;
    frmSearch->stg->Cells[3][t]=a.name.last;
    frmSearch->stg->Cells[4][t]=a.name.first;
    frmSearch->stg->Cells[5][t]=a.address.street;
    frmSearch->stg->Cells[6][t]=a.address.house;
    frmSearch->stg->Cells[7][t]=a.address.flat;
    frmSearch->stg->Cells[8][t]=a.receipt;
    t++;
    FNext();
  }
  a=FGet();
  frmSearch->stg->Cells[0][t]=IntToStr(a.id);
  frmSearch->stg->Cells[1][t]=a.number;
  frmSearch->stg->Cells[2][t]=a.mark;
  frmSearch->stg->Cells[3][t]=a.name.last;
  frmSearch->stg->Cells[4][t]=a.name.first;
  frmSearch->stg->Cells[5][t]=a.address.street;
  frmSearch->stg->Cells[6][t]=a.address.house;
  frmSearch->stg->Cells[7][t]=a.address.flat;
  frmSearch->stg->Cells[8][t]=a.receipt;
  t++;
  frmSearch->stg->RowCount=t;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSearch::btnSearchClick(TObject *Sender)
{   
  String s;
  s=frmSearch->edtSearch->Text;
  frmSearch->edtCount->Text=IntToStr(FSearch(s));
}
//---------------------------------------------------------------------------
void __fastcall TfrmSearch::stgSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
  FFindID(StrToInt(frmSearch->stg->Cells[0][ARow]));
}
//---------------------------------------------------------------------------
