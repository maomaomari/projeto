# Table of Contents

1.  [Projeto – Fila Encadeada e Árvores Binárias](#org438f109)
    1.  [i](#orgf499b60)
    2.  [ii](#org4210463)
    3.  [iii](#org73dcfdb)
    4.  [iv](#org99282ae)
    5.  [v](#org791ea6f)
    6.  [vi](#orgedf92f5)
    7.  [vii](#org00a9af9)
    8.  [viii](#orge68d765)
    9.  [ix](#orgd873cd7)

\#!TITLE:


<a id="org438f109"></a>

# Projeto – Fila Encadeada e Árvores Binárias

Desenvolver um programa em C que simule o controle de uma pista de decolagem de aviões em um aeroporto.
No programa, o usuário deve ser capaz de realizar as seguintes tarefas:


<a id="orgf499b60"></a>

## i

Cadastrar voos na Fila de espera;


<a id="org4210463"></a>

## ii

Cadastrar nomes na Lista de Passageiros de um voo (o usuário deve informar o ID do Voo desejado);


<a id="org73dcfdb"></a>

## iii

Remover nomes da Lista de Passageiros de um voo (o usuário deve informar o ID do Voo e Nome desejado);


<a id="org99282ae"></a>

## iv

Listar todas as características do primeiro avião da Fila (exceto a Lista de Passageiros);


<a id="org791ea6f"></a>

## v

Autorizar a decolagem do primeiro avião da Fila (removendo-o da fila);


<a id="orgedf92f5"></a>

## vi

Listar o número de aviões aguardando na Fila de decolagem;


<a id="org00a9af9"></a>

## vii

Listar os dados de todos os aviões na Fila de espera (um em cada linha da tela, exceto a Lista de Passageiros);

<!-- This HTML table template is generated by emacs 29.3 -->
<table border="1">
  <tr>
    <td align="left" valign="top">
	  id&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  destino
    </td>
    <td align="left" valign="top">
	  empresa
    </td>
    <td align="left" valign="top">
	  modelo&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  No.&nbsp;passageiros
    </td>
  </tr>
  <tr>
    <td align="left" valign="top">
	  GLO1123<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  CGH&nbsp;&nbsp;&nbsp;&nbsp;<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  GOL&nbsp;&nbsp;&nbsp;&nbsp;<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  Boeing&nbsp;&nbsp;<br />
	  737-7K5&nbsp;
    </td>
    <td align="left" valign="top">
	  138&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
  </tr>
  <tr>
    <td align="left" valign="top">
	  TAM3283<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  GRU&nbsp;&nbsp;&nbsp;&nbsp;<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  TAM&nbsp;&nbsp;&nbsp;&nbsp;<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  Airbus&nbsp;&nbsp;<br />
	  A321-211
    </td>
    <td align="left" valign="top">
	  220&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
  </tr>
  <tr>
    <td align="left" valign="top">
	  AZU4603<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  FLN&nbsp;&nbsp;&nbsp;&nbsp;<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  AZUL&nbsp;&nbsp;&nbsp;<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  ATR&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br />
	  72-600&nbsp;&nbsp;
    </td>
    <td align="left" valign="top">
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br />
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;78&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    </td>
  </tr>
</table>


<a id="orge68d765"></a>

## viii

Listar na tela os passageiros de um determinado voo em ordem alfabética e informar no final a quantidade
de passageiros no voo. O programa também deve exportar esses dados para um arquivo texto, colocando
como cabeçalho os dados do voo;


<a id="orgd873cd7"></a>

## ix

Sair do programa.
