<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<h4>어떤 차를 원하세요? (멀티 선택 가능)</h4>
<form method="post" action="save_car.jsp">
<table>  
<tr>
<td><img src="lam_m.jpg" width=300 height=180> </td>
<td><img src="lam_a.jpg" width=300 height=180> </td>
</tr>
<tr>
<th><input type="checkbox" name="car_n" value="노랑이(무르시엘라고 )" /> 노랑이(무르시엘라고 )</th>
<th><input type="checkbox" name="car_n" value="파랑이(아벤타도르)" /> 파랑이(아벤타도르)</th>
</tr>
<tr><td colspan="2"> &nbsp; </td></tr>  <!-- 중간에 좀 띄어주려고 -->
<tr>
<td><img src="lam_b.jpg" width=300 height=180> </td>
<td><img src="opti.jpg" width=300 height=180> </td>
</tr>
<tr>
<th><input type="checkbox" name="car_n" value="레드(베네노)" /> 레드(베네노)</th>
<th><input type="checkbox" name="car_n" value="옵티머스 프라임" /> 옵티머스 프라임도 차 맞음</th> 
</tr>
</table><p> 
<input type="submit" value="장바구니에 저장"> &nbsp;&nbsp;&nbsp;
<a href = "menu.jsp"> 메뉴로 돌아가기 </a>  
</form>