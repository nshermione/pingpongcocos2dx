<GameFile>
  <PropertyGroup Name="PlayScene" Type="Scene" ID="a16e4462-b67f-4cc4-b3c1-693a1e75ce88" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" Tag="10" ctype="GameNodeObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="bg" ActionTag="1798434540" Tag="29" IconVisible="False" ctype="SpriteObjectData">
            <Size X="1136.0000" Y="640.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="bg.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="topEdge" ActionTag="652436351" Tag="28" IconVisible="False" LeftMargin="17.1650" RightMargin="8.8350" TopMargin="-1.1281" BottomMargin="561.1281" Scale9Width="1" Scale9Height="1" ctype="ImageViewObjectData">
            <Size X="1110.0000" Y="80.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="572.1650" Y="601.1281" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5037" Y="0.9393" />
            <PreSize X="0.9771" Y="0.1250" />
            <FileData Type="Normal" Path="blank.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="botEdge" ActionTag="283906732" Tag="29" IconVisible="False" LeftMargin="13.7087" RightMargin="12.2913" TopMargin="609.3956" BottomMargin="-49.3956" Scale9Width="1" Scale9Height="1" ctype="ImageViewObjectData">
            <Size X="1110.0000" Y="80.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.7087" Y="-9.3956" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5006" Y="-0.0147" />
            <PreSize X="0.9771" Y="0.1250" />
            <FileData Type="Normal" Path="blank.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="blueGoal" ActionTag="659547072" Tag="21" IconVisible="False" LeftMargin="1040.8623" RightMargin="84.1377" TopMargin="88.9998" BottomMargin="41.0002" Scale9Width="11" Scale9Height="510" ctype="ImageViewObjectData">
            <Size X="11.0000" Y="510.0000" />
            <AnchorPoint ScaleX="0.5500" ScaleY="0.5000" />
            <Position X="1046.9124" Y="296.0002" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9216" Y="0.4625" />
            <PreSize X="0.0097" Y="0.7969" />
            <FileData Type="Normal" Path="blue_goal.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="purpleGoal" ActionTag="-795852724" Tag="19" IconVisible="False" LeftMargin="96.6979" RightMargin="1030.3021" TopMargin="85.0000" BottomMargin="37.0000" LeftEage="2" RightEage="2" TopEage="170" BottomEage="170" Scale9OriginX="2" Scale9OriginY="170" Scale9Width="5" Scale9Height="178" ctype="ImageViewObjectData">
            <Size X="9.0000" Y="518.0000" />
            <AnchorPoint ScaleX="0.5600" ScaleY="0.5000" />
            <Position X="101.7379" Y="296.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0896" Y="0.4625" />
            <PreSize X="0.0079" Y="0.8094" />
            <FileData Type="Normal" Path="purple_goal.png" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="menuButton" ActionTag="-1072537288" Tag="11" IconVisible="False" LeftMargin="1063.7434" RightMargin="8.2566" TopMargin="5.6671" BottomMargin="570.3329" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="34" Scale9Height="42" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="64.0000" Y="64.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1095.7434" Y="602.3329" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9646" Y="0.9411" />
            <PreSize X="0.0563" Y="0.1000" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Normal" Path="menu_btn_bg.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="clock" ActionTag="1086381205" Tag="11" IconVisible="False" LeftMargin="542.5000" RightMargin="542.5000" TopMargin="-2.6220" BottomMargin="619.6220" FontSize="20" LabelText="00:00" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="51.0000" Y="23.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="631.1220" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="0" G="0" B="0" />
            <PrePosition X="0.5000" Y="0.9861" />
            <PreSize X="0.0449" Y="0.0359" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="purpleName" ActionTag="-826116389" Tag="12" IconVisible="False" LeftMargin="364.6133" RightMargin="654.3867" TopMargin="37.6282" BottomMargin="573.3718" FontSize="24" LabelText="Purple Name" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="117.0000" Y="29.0000" />
            <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
            <Position X="481.6133" Y="587.8718" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4240" Y="0.9185" />
            <PreSize X="0.1030" Y="0.0453" />
            <FontResource Type="Normal" Path="Marker Felt.ttf" Plist="" />
            <OutlineColor A="255" R="238" G="33" B="211" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="blueName" ActionTag="1700350749" Tag="13" IconVisible="False" LeftMargin="647.8251" RightMargin="388.1749" TopMargin="36.2693" BottomMargin="574.7307" FontSize="24" LabelText="Blue Name" OutlineSize="2" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="100.0000" Y="29.0000" />
            <AnchorPoint ScaleY="0.5000" />
            <Position X="647.8251" Y="589.2307" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5703" Y="0.9207" />
            <PreSize X="0.0880" Y="0.0453" />
            <FontResource Type="Normal" Path="Marker Felt.ttf" Plist="" />
            <OutlineColor A="255" R="0" G="20" B="137" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="purpleScore" ActionTag="899889705" Tag="15" IconVisible="False" LeftMargin="525.9117" RightMargin="583.0883" TopMargin="25.2369" BottomMargin="562.7631" FontSize="42" LabelText="0" OutlineSize="4" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="27.0000" Y="52.0000" />
            <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
            <Position X="552.9117" Y="588.7631" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4867" Y="0.9199" />
            <PreSize X="0.0238" Y="0.0812" />
            <FontResource Type="Normal" Path="Marker Felt.ttf" Plist="" />
            <OutlineColor A="255" R="238" G="33" B="211" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="blueScore" ActionTag="-905341248" Tag="16" IconVisible="False" LeftMargin="580.4135" RightMargin="528.5865" TopMargin="25.1047" BottomMargin="562.8953" FontSize="42" LabelText="0" OutlineSize="4" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="27.0000" Y="52.0000" />
            <AnchorPoint ScaleY="0.5000" />
            <Position X="580.4135" Y="588.8953" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5109" Y="0.9201" />
            <PreSize X="0.0238" Y="0.0812" />
            <FontResource Type="Normal" Path="Marker Felt.ttf" Plist="" />
            <OutlineColor A="255" R="11" G="103" B="207" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="purpleChump" ActionTag="1684007233" Tag="22" IconVisible="False" LeftMargin="117.6192" RightMargin="898.3808" TopMargin="286.0000" BottomMargin="238.0000" ctype="SpriteObjectData">
            <Size X="120.0000" Y="116.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="177.6192" Y="296.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1564" Y="0.4625" />
            <PreSize X="0.1056" Y="0.1813" />
            <FileData Type="Normal" Path="chump3.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="blueChump" ActionTag="1116463291" Tag="23" IconVisible="False" LeftMargin="913.0067" RightMargin="102.9933" TopMargin="286.0000" BottomMargin="238.0000" FlipX="True" ctype="SpriteObjectData">
            <Size X="120.0000" Y="116.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="973.0067" Y="296.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8565" Y="0.4625" />
            <PreSize X="0.1056" Y="0.1813" />
            <FileData Type="Normal" Path="chump3.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="arrow" ActionTag="169550659" Tag="24" IconVisible="False" LeftMargin="550.2633" RightMargin="549.7367" TopMargin="315.2760" BottomMargin="266.7240" ctype="SpriteObjectData">
            <Size X="36.0000" Y="58.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.2633" Y="295.7240" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5002" Y="0.4621" />
            <PreSize X="0.0317" Y="0.0906" />
            <FileData Type="Normal" Path="arrow.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="purpleBlock" ActionTag="-283946324" Tag="25" IconVisible="False" LeftMargin="437.0623" RightMargin="640.9377" TopMargin="213.5205" BottomMargin="368.4795" ctype="SpriteObjectData">
            <Size X="58.0000" Y="58.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="466.0623" Y="397.4795" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4103" Y="0.6211" />
            <PreSize X="0.0511" Y="0.0906" />
            <FileData Type="Normal" Path="barrier.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="blueBlock" ActionTag="158910904" Tag="26" IconVisible="False" LeftMargin="641.0526" RightMargin="436.9474" TopMargin="410.0779" BottomMargin="171.9221" ctype="SpriteObjectData">
            <Size X="58.0000" Y="58.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="670.0526" Y="200.9221" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5898" Y="0.3139" />
            <PreSize X="0.0511" Y="0.0906" />
            <FileData Type="Normal" Path="barrier.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="bluePortal" ActionTag="277631571" Tag="27" IconVisible="False" LeftMargin="682.4946" RightMargin="409.5054" TopMargin="194.0157" BottomMargin="404.9843" ctype="SpriteObjectData">
            <Size X="44.0000" Y="41.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="704.4946" Y="425.4843" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6202" Y="0.6648" />
            <PreSize X="0.0387" Y="0.0641" />
            <FileData Type="Normal" Path="portal.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="bluePortalCollider" ActionTag="-1909373625" Tag="117" IconVisible="False" LeftMargin="703.7792" RightMargin="431.2208" TopMargin="214.5000" BottomMargin="424.5000" ctype="SpriteObjectData">
            <Size X="1.0000" Y="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="704.2792" Y="425.0000" />
            <Scale ScaleX="11.0000" ScaleY="10.6000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6200" Y="0.6641" />
            <PreSize X="0.0009" Y="0.0016" />
            <FileData Type="Normal" Path="blank.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="purplePortal" ActionTag="-840372630" Tag="28" IconVisible="False" LeftMargin="418.0731" RightMargin="673.9269" TopMargin="452.9158" BottomMargin="146.0842" ctype="SpriteObjectData">
            <Size X="44.0000" Y="41.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="440.0731" Y="166.5842" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.3874" Y="0.2603" />
            <PreSize X="0.0387" Y="0.0641" />
            <FileData Type="Normal" Path="portal.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="purplePortalCollider" ActionTag="1161880688" Tag="116" IconVisible="False" LeftMargin="439.4742" RightMargin="695.5258" TopMargin="473.1001" BottomMargin="165.8999" ctype="SpriteObjectData">
            <Size X="1.0000" Y="1.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="439.9742" Y="166.3999" />
            <Scale ScaleX="11.0000" ScaleY="10.6000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.3873" Y="0.2600" />
            <PreSize X="0.0009" Y="0.0016" />
            <FileData Type="Normal" Path="blank.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="ball" ActionTag="578193936" Tag="13" IconVisible="False" LeftMargin="550.0037" RightMargin="553.9963" TopMargin="329.0386" BottomMargin="278.9614" ctype="SpriteObjectData">
            <Size X="32.0000" Y="32.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="566.0037" Y="294.9614" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4982" Y="0.4609" />
            <PreSize X="0.0282" Y="0.0500" />
            <FileData Type="Normal" Path="ball.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="moneyBar" ActionTag="-768278576" Tag="102" IconVisible="False" LeftMargin="833.2437" RightMargin="120.7563" TopMargin="11.3330" BottomMargin="588.6670" TouchEnable="True" ClipAble="True" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="90.0000" LeftEage="60" RightEage="60" TopEage="13" BottomEage="13" Scale9OriginX="-60" Scale9OriginY="-13" Scale9Width="120" Scale9Height="26" ctype="PanelObjectData">
            <Size X="182.0000" Y="40.0000" />
            <Children>
              <AbstractNodeData Name="Image_1" ActionTag="772038961" Tag="103" IconVisible="False" LeftEage="60" RightEage="60" TopEage="13" BottomEage="13" Scale9OriginX="60" Scale9OriginY="13" Scale9Width="62" Scale9Height="14" ctype="ImageViewObjectData">
                <Size X="182.0000" Y="40.0000" />
                <AnchorPoint />
                <Position />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="1.0000" Y="1.0000" />
                <FileData Type="Normal" Path="money_bar.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Image_14" ActionTag="-1796131335" Tag="104" IconVisible="False" LeftMargin="15.4820" RightMargin="149.5180" TopMargin="7.9011" BottomMargin="9.0989" LeftEage="5" RightEage="5" TopEage="7" BottomEage="7" Scale9OriginX="5" Scale9OriginY="7" Scale9Width="7" Scale9Height="9" ctype="ImageViewObjectData">
                <Size X="17.0000" Y="23.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="23.9820" Y="20.5989" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.1318" Y="0.5150" />
                <PreSize X="0.0934" Y="0.5750" />
                <FileData Type="Normal" Path="money_icon.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="money" ActionTag="181647972" Tag="105" IconVisible="False" LeftMargin="44.8102" RightMargin="19.1898" TopMargin="8.6638" BottomMargin="8.3362" FontSize="20" LabelText="123456789012" OutlineEnabled="True" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="118.0000" Y="23.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="44.8102" Y="19.8362" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2462" Y="0.4959" />
                <PreSize X="0.6484" Y="0.5750" />
                <FontResource Type="Normal" Path="Marker Felt.ttf" Plist="" />
                <OutlineColor A="255" R="49" G="40" B="18" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="833.2437" Y="588.6670" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7335" Y="0.9198" />
            <PreSize X="0.1602" Y="0.0625" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>