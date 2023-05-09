package pg1;

import weka.core.converters.ArffSaver;
import weka.core.converters.CSVSaver;
import weka.core.converters.ConverterUtils.DataSource;
import weka.core.Instances;
import weka.filters.Filter;
import weka.filters.unsupervised.instance.RemovePercentage;
import weka.filters.unsupervised.instance.Resample;

import java.io.File;
import java.io.IOException;

public class MyKnowledgeModel {
    DataSource source; // Lưu nguồn dữ liệu
    Instances dataset; // Lưu giữ dữ liệu đầu vào
    Instances trainSet;
    Instances testSet;
    String[] model_options; // các tham số của mô hình
    String[] data_options; // các tham số xử lý dữ liệu

    public MyKnowledgeModel() {
    }

    public MyKnowledgeModel(String fileName, String m_opts, String d_opts) throws Exception {

        this.source = new DataSource(fileName);
        this.dataset = source.getDataSet();
        if (m_opts != null) {
            this.model_options = weka.core.Utils.splitOptions(m_opts);
        }
        if (d_opts != null) {
            this.data_options = weka.core.Utils.splitOptions(d_opts);
        }
    }


    @Override
    public String toString() {
        return dataset.toSummaryString();
    }

    public void saveData(String filename) throws IOException {
        ArffSaver outData = new ArffSaver();
        outData.setInstances(this.dataset);
        outData.setFile(new File(filename));
        outData.writeBatch();
        System.out.println("Saving finished!");
    }

    public void saveData2CSV(String filename) throws IOException {
        CSVSaver outData = new CSVSaver();
        outData.setInstances(this.dataset);
        outData.setFile(new File(filename));
        outData.writeBatch();
        System.out.println("Converted!");
    }

    public Instances divideTrainTest(Instances originalSet, double percent, boolean isTest) throws Exception {
        RemovePercentage rp = new RemovePercentage();
        rp.setPercentage(percent);
        rp.setInvertSelection(isTest);
        rp.setInputFormat(originalSet);
        return Filter.useFilter(originalSet, rp);
    }

    public Instances divideTrainTestR(Instances originalSet, double percent, boolean isTest) throws Exception {
        Resample rs = new Resample();
        rs.setNoReplacement(true);
        rs.setSampleSizePercent(percent);
        rs.setInvertSelection(isTest);
        rs.setInputFormat(originalSet);
        return Filter.useFilter(originalSet, rs);
    }

    public void setTrainSet(String fileName) throws Exception {
        this.trainSet = this.source.getDataSet();
    }

    public void setTestSet(String fileName) throws Exception {
        this.testSet = this.source.getDataSet();
    }
}