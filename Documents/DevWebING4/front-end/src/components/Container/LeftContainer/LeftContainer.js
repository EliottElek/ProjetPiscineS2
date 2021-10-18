import React from "react";
import Channels from "../Channels/Channels";
import SearchBar from "../Channels/SearchBar/SearchBar";
import { Grid } from "@mui/material";

const styles = {
  grid: {
    height: "100%",
  },
  topGrid: {
    display: "flex",
    padding:"12x 0px 12px 0px",
    justifyContent: "center",
    alignItems: "center",
    background: "#2f3136",
    borderBottom:'solid 1.5px #232428'
  },
};
const LeftContainer = ({ channels, message }) => {
  return (
    <Grid sx={styles.grid} container direction="column">
      <Grid style={styles.topGrid} item xs={1} md={1} lg={1} xl={1}>
        <SearchBar channels={channels} place={"Find a channel..."}/>
      </Grid>
      <Grid item xs={11} md={11} lg={11} xl={11}>
        <Channels channels={channels} message={message} />
      </Grid>
    </Grid>
  );
};

export default LeftContainer;
