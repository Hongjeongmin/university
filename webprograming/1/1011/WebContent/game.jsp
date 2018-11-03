<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>notebook_buy!</title>
</head>
<body style="background-color:lime">
<%
%>
	<h2>게임</h2>

	<form method="post" action="save_product.jsp">
		<input type ="hidden" name="how" value="game"/>
		<table border="1">
		<tr>
			<th>No</th><th>이름</th><th>이미지</th><th>가격</th>
		</tr>
		<tr>
			<td><input type="checkbox" name = "product" name="game" value="GTA" /></td><td>GTA</td><td><img src="D:\university\webprograming\1\1011\WebContent\gta.jpg" width=250 height=250></td><td>500</td>
		</tr>
		<tr>
			<td><input type="checkbox" name = "product" name="game" value="LOL"/></td><td>LOL</td><td><img src="D:\university\webprograming\1\1011\WebContent\lol.jpg" width=250 height=250></td><td>100</td>
		</tr>
		<tr>
			<td><input type="checkbox" name = "product" name="game" value="Starcraft"/></td><td>Starcraft</td><td><img src="D:\university\webprograming\1\1011\WebContent\star.jpg" width=250 height=250></td><td>400</td>
		</tr>
		<tr>
			<td><input type="checkbox" name = "product" name="game" value="Starcraft"/></td><td>Starcraft</td><td><img src="D:\university\webprograming\1\1011\WebContent\star.jpg" width=250 height=250></td><td>400</td>
		</tr>				
		</table>
		<p>
		<p>

		<input type="submit" value="장바구니에 담기"/> &nbsp;&nbsp;
		<a href="menu.jsp">메뉴</a>
	</form>

</body>
</html>