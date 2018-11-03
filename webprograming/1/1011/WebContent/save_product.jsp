<% request.setCharacterEncoding("UTF-8");%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

	<%String[] product = request.getParameterValues("product");%>
	<% String how = request.getParameter("how"); %>
	<%
	if(product!=null)
	{%>
		<%ArrayList<String> arr =(ArrayList)(session.getAttribute("arr")); %>
		
		<%
		if(arr==null){arr = new ArrayList<String>();}
		for(int i= 0;i<product.length;i++) arr.add(product[i]);
		session.setAttribute("arr", arr);
		%>
		
		<script>
		alert("장바구니에 담았습니다!");
		<%if(how.equals("notebook")){%>
			location.href="notebook.jsp";
		<%}
		else if(how.equals("car")){%>
			location.href="car.jsp";
		<%}
		else{%>
			location.href="game.jsp";
		<%}%>
		</script>
	<%}
	else
	{%>
		<script>
		alert("선택해주세요 ㅜㅜ");
		<%if(how.equals("notebook")){%>
			location.href="notebook.jsp";
		<%}
		else if(how.equals("car")){%>
			location.href="car.jsp";
		<%}
		else{%>
			location.href="game.jsp";
		<%}%>	
		</script>
	<%}%>
	

</body>
</html>