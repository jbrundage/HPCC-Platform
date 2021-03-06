import * as React from "react";
import { CommandBar, DefaultPalette, FontSizes, FontWeights, ICommandBarItemProps, Stack } from "@fluentui/react";
import { IconStack } from "./stacks/IconStack";
import { StackTable } from "./visualizations/StackTable";
import { useWorkunitResults } from "../hooks/Workunit";
import { QuartileStats } from "./visualizations/QuartileStats";
import { BreakdownTable } from "./visualizations/BreakdownTable";
import { HolyGrail } from "../layouts/HolyGrail";
// import { ShortVerticalDivider } from "./Common";
// import nlsHPCC from "src/nlsHPCC";

interface DataPatternsReportProps {
    Wuid: string;
}

interface NAStackTableProps {
    label: string;
    value: string;
}

const labelStyles = {
    root: {
        height: FontSizes.medium,
        fontSize: FontSizes.small,
        lineHeight: FontSizes.small,
        fontWeight: FontWeights.bold
    }
};

export const NAStackTable: React.FunctionComponent<NAStackTableProps> = ({
    label,
    value
}) => {
    return <StackTable
        label={label}
        labelStyles={labelStyles}
        data={[
            [value, ""],
        ]}
    />;
};

export const DataPatternsReport: React.FunctionComponent<DataPatternsReportProps> = ({
    Wuid
}) => {

    const wuResults = useWorkunitResults(Wuid);
    const [results] = wuResults;

    const [data, setData] = React.useState([]);
    const [hideStrings, setHideStrings] = React.useState(false);
    const [hideNumbers, setHideNumbers] = React.useState(false);
    const [sortBy, setSortBy] = React.useState("default");

    React.useEffect(() => {
        if (results && results[0]) {
            results[0].fetchRows().then((resp) => {
                resp.forEach((n, i)=>{
                    n.originalIndex = i;
                    n.typeCategory = n.given_attribute_type.toLowerCase().includes("string") ? 1 : 0;
                    if(n.is_numeric) {
                        n.typeCategory = 0;
                    }
                });
                setData(resp);
            });
        } else {
            setData([]);
        }
    }, [results]);

    const stackParams = {};
    data.sort((a, b)=>{
        switch(sortBy){
            case "default":
                return a.originalIndex - b.originalIndex;
            case "cardinality_asc":
                if(a.cardinality === b.cardinality) {
                    return a.cardinality - b.cardinality;
                }
                return a.cardinality - b.cardinality;
            case "cardinality_desc":
                if(a.cardinality === b.cardinality) {
                    return a.cardinality - b.cardinality;
                }
                return b.cardinality - a.cardinality;
        }
    });

    const items = data
        .filter(item=>{
            const isLegitAsNumber = item.is_numeric || !hideStrings;
            const isLegitAsString = !item.is_numeric || !hideNumbers;
            return isLegitAsNumber && isLegitAsString;
        })
        .map((item, rowIdx) => {
            let col1Content;
            let col2Widget;
            let col3Widget;
            let col4Widget;

            const col0Styles = {
                root: {
                    width: "20%",
                    marginRight: "2%",
                    marginLeft: "2%",
                },
            };
            const col1Styles = {
                root: {
                    width: "14%",
                    marginRight: "2%",
                },
            };
            const col2Styles = {
                root: {
                    width: "20%",
                    minWidth: "auto",
                    marginRight: "2%",
                },
            };
            const col3Styles = {
                root: {
                    width: "18%",
                    marginRight: "2%",
                },
            };
            const col4Styles = {
                root: {
                    width: "16%",
                    minWidth: "200px",
                    marginRight: "2%",
                },
            };

            let bestType = item.best_attribute_type;
            if (bestType !== item.given_attribute_type) {
                bestType = {
                    styles: {
                        root: {
                            color: DefaultPalette.red,
                            fontWeight: FontWeights.bold
                        }
                    },
                    text: item.best_attribute_type
                };
            }
            let fillRate;
            if (item.fill_rate < 30) {
                fillRate = {
                    styles: {
                        root: {
                            color: DefaultPalette.red,
                            fontWeight: FontWeights.bold
                        }
                    },
                    text: item.fill_rate === 100 || item.fill_rate === 0 ? item.fill_rate + "%" : item.fill_rate.toFixed(1) + "%"
                };
            } else {
                fillRate = item.fill_rate === 100 || item.fill_rate === 0 ? item.fill_rate + "%" : item.fill_rate.toFixed(1) + "%";
            }
            const col0Content = <IconStack
                label={item.attribute}
                iconName={
                    item.given_attribute_type.slice(0, 6) === "string" ? "HalfAlpha" : "NumberSymbol"
                }
                data={
                    [
                        ["Given Type", item.given_attribute_type],
                        ["Best Type", bestType],
                        ["Cardinality", item.cardinality],
                        ["Filled", item.fill_count],
                        ["% Filled", fillRate],
                    ]
                }
            />;
            if (item.is_numeric) {
                col1Content = <StackTable
                    labelStyles={
                        {
                            root: {
                                flex: 1,
                                overflow: "hidden",
                                height: 19,
                                fontWeight: FontWeights.bold
                            }
                        }
                    }
                    valueStyles={{ root: { flex: 0 } }}
                    data={
                        [
                            ["Mean", item.min_length],
                            ["Std. Dv", item.ave_length],
                            ["Min", item.numeric_min],
                            ["25%", item.numeric_lower_quartile],
                            ["50%", item.numeric_median],
                            ["75%", item.numeric_upper_quartile],
                            ["Max", item.numeric_max],
                        ]
                    }
                />;
                col2Widget = <QuartileStats
                    mean={item.numeric_mean}
                    standardDeviation={item.numeric_std_dev}
                    tickFormat={".2e"}
                    showBell={true}
                    showCandlestick={true}
                    bellHeight={123}
                    quartiles={[
                        item.numeric_min,
                        item.numeric_lower_quartile,
                        item.numeric_median,
                        item.numeric_upper_quartile,
                        item.numeric_max
                    ]}
                />;
            } else {
                col1Content = <StackTable
                    labelStyles={
                        {
                            root: {
                                flex: 1,
                                overflow: "hidden",
                                fontSize: FontSizes.small,
                                height: 19
                            }
                        }
                    }
                    valueStyles={{ root: { flex: 0 } }}
                    data={
                        [
                            ["Min Length", item.min_length],
                            ["Avg Length", item.ave_length],
                            ["Max Length", item.max_length],
                        ]
                    }
                />;
                if(item.rare_patterns && item.rare_patterns.Row.length) {
                    col2Widget = <BreakdownTable
                        label="Rare Patterns"
                        data={item.rare_patterns.Row.map(n => {
                            return [
                                n.data_pattern.trim(), n.rec_count
                            ];
                        })}
                        rowCount={7}
                        usePercentage={true}
                    />;
                    col2Styles.root.minWidth = "200px";
                } else {
                    col2Widget = <NAStackTable label="Rare Patterns" value="N/A" />;
                }
            }
            if (item.popular_patterns.Row.length > 0) {
                col4Widget = <BreakdownTable
                    label="Patterns"
                    data={item.popular_patterns.Row.map(n => {
                        return [
                            n.data_pattern.trim(), n.rec_count
                        ];
                    })}
                    rowCount={7}
                    usePercentage={true}
                />;
            } else {
                col4Widget = <NAStackTable label="Popular Patterns" value="N/A" />;
            }

            if (item.cardinality_breakdown.Row.length > 0) {
                col3Widget = <BreakdownTable
                    label="Cardinality"
                    data={item.cardinality_breakdown.Row.map(n => {
                        return [
                            n.value.trim(), n.rec_count
                        ];
                    })}
                    rowCount={7}
                    usePercentage={true}
                />;
            } else {
                col3Widget = <NAStackTable label="Cardinality" value="N/A" />;
            }

            const evenRowStackStyles = {
                root: {
                    paddingTop: 12,
                    paddingBottom: 12,
                },
            };
            const oddRowStackStyles = {
                root: {
                    backgroundColor: "#cccccc",
                    paddingTop: 12,
                    paddingBottom: 12,
                },
            };
            return <Stack key={`row-stack-${rowIdx}`} horizontal styles={rowIdx % 2 ? oddRowStackStyles : evenRowStackStyles}>
                <Stack.Item key="stack-item-0" styles={col0Styles}>
                    {col0Content}
                </Stack.Item>
                <Stack.Item key="stack-item-1" styles={col1Styles}>
                    {col1Content}
                </Stack.Item>
                <Stack.Item key="stack-item-2" styles={col2Styles}>
                    {col2Widget}
                </Stack.Item>
                <Stack.Item key="stack-item-3" styles={col3Styles}>
                    {col3Widget}
                </Stack.Item>
                <Stack.Item key="stack-item-4" styles={col4Styles}>
                    {col4Widget}
                </Stack.Item>
            </Stack>;
        });
    const buttons: ICommandBarItemProps[] = [
        {
            key: "toggleStrings", text: "Show/Hide Strings", iconProps: { iconName: "Filter" },
            onClick: () => {
                setHideStrings(!hideStrings);
            }
        },
        {
            key: "toggleNumbers", text: "Show/Hide Numbers", iconProps: { iconName: "Filter" },
            onClick: () => {
                setHideNumbers(!hideNumbers);
            }
        },
    ];
    const rightButtons: ICommandBarItemProps[] = [
        {
            key: "sorting",
            text: "Sort By",
            iconProps: { iconName: "Sort" },
            subMenuProps: {
                items: [
                    {
                        key: "default",
                        text: "Default",
                        onClick: () => {
                            setSortBy("default");
                        }
                    },
                    {
                        key: "cardinality_desc",
                        text: "Cardinality DESC",
                        onClick: () => {
                            setSortBy("cardinality_desc");
                        }
                    },
                    {
                        key: "cardinality_asc",
                        text: "Cardinality ASC",
                        onClick: () => {
                            setSortBy("cardinality_asc");
                        }
                    },
                ],
            },
        },
    ];
    return <HolyGrail
        header={
            <Stack>
                <Stack.Item>
                    <CommandBar
                        items={buttons}
                        farItems={rightButtons}
                    />
                </Stack.Item>
            </Stack>
        }
        main={
            <Stack
                {...stackParams}
            >
                {items}
            </Stack>
        }
    />;
};
