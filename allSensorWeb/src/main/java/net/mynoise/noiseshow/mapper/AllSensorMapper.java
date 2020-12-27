package net.mynoise.noiseshow.mapper;
import net.mynoise.noiseshow.entity.AllSensor;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Repository;

import java.util.List;
/*** 
 @author: 葛璐豪
 @学号:201741882228
 */
@Repository
public interface AllSensorMapper {
    @Select("SELECT * FROM allSensor_data")
    public List<AllSensor> querrySensor();

    @Insert({ "insert into " +
            "allSensor_data(id, people,dist,light,temp.hum,ip,time) " +
            "values(#{id},#{people},#{dist},#{light},#{temp},#{hum},#{ip},#{time})" })
    public int insertData(AllSensor allSensor);
}
