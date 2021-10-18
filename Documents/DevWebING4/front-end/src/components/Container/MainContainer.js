import React from "react";
import { Grid } from "@mui/material";
import Channel from "./Channel/Channel";
import RightContainer from "./RightContainer/RightContainer";
import LeftContainer from "./LeftContainer/LeftContainer";

const styles = {
  container: {
    width: "100%",
    height: "100vh",
    padding: 0,
    margin: 0,
  },
};

const MainContainer = ({ messages, channels, channel, addMessage }) => {
  return (
    <Grid container style={styles.container}>
      <Grid item xs={4} md={3} lg={2} xl={2}>
        <LeftContainer
          channels={channels}
          message={messages[messages.length - 1]}
        />
      </Grid>
      <Grid item xs={8} md={9} lg={10} xl={10}>
        <Channel
          messages={messages}
          channel={channel}
          addMessage={addMessage}
        />
      </Grid>
    </Grid>
  );
};

export default MainContainer;
