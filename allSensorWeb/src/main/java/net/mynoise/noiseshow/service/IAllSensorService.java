package net.mynoise.noiseshow.service;

import net.mynoise.noiseshow.entity.AllSensor;

import java.util.List;

/***
 @author: 葛璐豪
 @学号:201741882228
 */
public interface IAllSensorService {
    public List<AllSensor> querrySensor();

    public int insertData(AllSensor allSensor);
}
