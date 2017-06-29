package cn.cslg.Ajax;

import cn.cslg.tools.DataStruts;
import cn.cslg.tools.GetData;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


/**
 * Created by Administrator on 2017/5/11.
 */
public class AjaxGetData extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws IOException, ServletException {

        PrintWriter out = response.getWriter();

        GetData getData = new GetData();
        ArrayList<DataStruts> informations = getData.getInformations();

        for(int i = 0; i < informations.size(); ++i) {
            out.println("<div class=\"text\">\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t<div class=\"text-left\">\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t\t<span class=\"star active\"> </span>\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t</div>\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t<div class=\"text-right\">\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t\t<h4><a href=\"#\">标题</a></h4> <label>" + informations.get(i).getTime() + " </label>\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t\t<div class=\"clear\"> </div>\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t\t<p>" + informations.get(i).getInformation() + " </p>\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t\t<p class=\"from\">来自</p>\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t\t<h6> 树莓派3B+</h6>\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t</div>\n" +
                    "\t\t\t\t\t\t\t\t\t\t\t<div class=\"clear\"> </div>\n" +
                    "\t\t\t\t\t\t\t\t\t\t</div>");
        }
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws IOException, ServletException {
        doGet(request,response);
    }
}