package net.mynoise.noiseshow.netty;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;
import net.mynoise.noiseshow.entity.AllSensor;
import net.mynoise.noiseshow.service.IAllSensorService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import java.net.InetSocketAddress;
import java.text.SimpleDateFormat;
import java.util.Date;

/*** 
 @author: 葛璐豪
 @学号:201741882228
 */
@Component
public class NettyServerHandler extends ChannelInboundHandlerAdapter {
    /**获取实例化对象*/
    @Autowired
    protected IAllSensorService allSensorService;

    private static NettyServerHandler serverHandler;

    /**配合@Component注解获取service层的bean*/
    @PostConstruct
    public void init(){
        serverHandler = this;
        serverHandler.allSensorService = this.allSensorService;
    }

    /**
     * 客户端连接会触发
     */
    @Override
    public void channelActive(ChannelHandlerContext ctx) throws Exception {
        System.out.println("客户端发起连接！！！！");
    }

    /**
     * 客户端发消息会触发
     */
    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) throws Exception {
        /**获取客户端的IP*/
        InetSocketAddress insocket = (InetSocketAddress)ctx.channel().remoteAddress();
        String ip = insocket.getAddress().getHostAddress();
        /**将RGB数据处理*/
        String tem = msg.toString();

        System.out.println("服务器接收到客户端的rgb---"+msg.toString());
        //people=1,dist=1,light=3,temp=4,hum=5
        String tem1[] = tem.split("=");
        if(tem1.length==6) {
            try {
                AllSensor allSensor = new AllSensor();
                String people = tem1[1].split(",")[1];
                String dist = tem1[2].split(",")[1];
                String light = tem1[3].split(",")[1];
                String temp = tem1[4].split(",")[1];
                String hum = tem1[5].split(",")[1];
                allSensor.setPeople(people);
                allSensor.setDist(dist);
                allSensor.setLight(light);
                allSensor.setTemp(temp);
                allSensor.setHum(hum);
                Date time=new Date();
                SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                allSensor.setTime(df.format(time));
                allSensor.setIp("192.168.43.125");
                serverHandler.allSensorService.insertData(allSensor);
                System.out.println(allSensor+"写入数据库成功！！！！");
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("抛弃该数据");
            }
        }
        /**调用业务层方法将数据写入数据库*/
        System.out.println(tem);
//        ctx.write("receive OK!");
        ctx.flush();
    }

    /**
     * 发生异常触发
     */
    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) throws Exception {
        cause.printStackTrace();
        ctx.close();
    }

    @Override
    public void channelInactive(ChannelHandlerContext ctx) throws Exception {
        System.out.println("客户端连接断开！！！！！！！！");
    }
}
